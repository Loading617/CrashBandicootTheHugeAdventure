#ifndef QOA_H
#define QOA_H

#ifdef __cplusplus
extern "C" {
#endif

#define QOA_MIN_FILESIZE 16
#define QOA_MAX_CHANNELS 8

#define QOA_SLICE_LEN 20
#define QOA_SLICES_PER_FRAME 256
#define QOA_FRAME_LEN (QOA_SLICES_PER_FRAME * QOA_SLICE_LEN)
#define QOA_LMS_LEN 4
#define QOA_MAGIC 0x716f6166 /* 'qoaf' */

#define QOA_FRAME_SIZE(channels, slices) \
	(8 + QOA_LMS_LEN * 4 * channels + 8 * slices * channels)

typedef struct {
	int history[QOA_LMS_LEN];
	int weights[QOA_LMS_LEN];
} qoa_lms_t;

typedef struct {
	unsigned int channels;
	unsigned int samplerate;
	unsigned int samples;
	qoa_lms_t lms[QOA_MAX_CHANNELS];
	#ifdef QOA_RECORD_TOTAL_ERROR
		double error;
	#endif
} qoa_desc;

unsigned int qoa_encode_header(qoa_desc *qoa, unsigned char *bytes);
unsigned int qoa_encode_frame(const short *sample_data, qoa_desc *qoa, unsigned int frame_len, unsigned char *bytes);
void *qoa_encode(const short *sample_data, qoa_desc *qoa, unsigned int *out_len);

unsigned int qoa_max_frame_size(qoa_desc *qoa);
unsigned int qoa_decode_header(const unsigned char *bytes, int size, qoa_desc *qoa);
unsigned int qoa_decode_frame(const unsigned char *bytes, unsigned int size, qoa_desc *qoa, short *sample_data, unsigned int *frame_len);
short *qoa_decode(const unsigned char *bytes, int size, qoa_desc *file);

#ifndef QOA_NO_STDIO

int qoa_write(const char *filename, const short *sample_data, qoa_desc *qoa);
void *qoa_read(const char *filename, qoa_desc *qoa);

#endif /* QOA_NO_STDIO */


#ifdef __cplusplus
}
#endif
#endif /* QOA_H */

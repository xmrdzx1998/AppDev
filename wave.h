/* Usually there are 3 parts in a header file
	the first part is data structure definition,
	the second part is a list of defined constants,
	the third part is a list of function prototype */

// data structure definition
typedef struct{
	char ChunkID[4];
	int ChunkSize;
	char Format[4];
	char Subchunk1ID[4];
	int Subchunk1Size;
	short int AudioFormat;
	short int NumChannels;
	int SampleRate;
	int ByteRate;
	short int BlockAlign;
	short int BitsperSample;
	char Subchunk2ID[4];
	int Subchunk2Size;
}WAVHDR;

// constant definitions
//#define DEBUG 1	// this line makes conditional compiling
#define SAMPLE_RATE 16000
#define PI 3.1415926

// function prototypes
void dispWAVHDR(WAVHDR);
void testTone(int f, double d);
void dispWAVdata(short int s[]);

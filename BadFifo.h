#ifndef _BAD_FIFO_H_
#define _BAD_FIFO_H_
//***************FIFO Implementation with critical section****
#define BadFIFOSIZE 32   
#define BadFIFOSUCCESS 1
#define BadFIFOFAIL    0

typedef unsigned char BaddataType;
unsigned long static volatile BadSize; /* number of elements in FIFO */
BaddataType static volatile *BadPutPt;    /* Pointer of where to put next */
BaddataType static volatile *BadGetPt;    /* Pointer of where to get next */
BaddataType static BadFifo[BadFIFOSIZE];

/*-----------------------BadFifo_Init----------------------------
  Initialize fifo to be empty
  Inputs: none
  Outputs: none */
void BadFifo_Init(void);


/*-----------------------BadFifo_Put----------------------------
  Enter one character into the fifo
  Inputs: data
  Outputs: true if data is properly saved,
           false if data not saved because it was previously full*/
int BadFifo_Put(BaddataType data);

/*-----------------------BadFifo_Get----------------------------
  Remove one character from the fifo
  Inputs: pointer to place to return data
  Outputs: true if data is valid, 
           false if fifo was empty at the time of the call*/
int BadFifo_Get(BaddataType *datapt);

//-----------------------BadFifo_Size----------------------------
// Check the status of the FIFO
// Inputs: none
// Outputs: number of elements currently stored
// 0 to FIFOSIZE (0 means empty, FIFOSIZE-1 means full)
unsigned long BadFifo_Size(void);
#endif


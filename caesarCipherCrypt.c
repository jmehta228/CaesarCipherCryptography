#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define SHIFT_AMOUNT 3

void encryptFile(FILE *inputFilePtr, FILE *outputFilePtr);

void decryptFile(FILE *inputFilePtr, FILE *outputFilePtr);

int userShiftAmount;

int main(void) {
	int operation;
	printf("\n\n\n");
//        printf("\t———————————————————————————————————————————————————\n");
	printf("\t****************************************************\n");
	printf("\t*                                                  *\n");  
	printf("\t*          TEXT FILE CRYPTOGRAPHY PROGRAM          *\n");
	printf("\t*                                                  *\n");
        printf("\t*                                                  *\n");
        printf("\t*                        MENU                      *\n");
        printf("\t*                                                  *\n");
       	printf("\t*                 1. Encrypt a file                *\n");
	printf("\t*                 2. Decrypt a file                *\n");
        printf("\t*                                                  *\n");
        printf("\t*                                                  *\n");
        printf("\t*                                                  *\n");
        printf("\t*                                                  *\n");
        printf("\t****************************************************\n");
	printf("\n");
	printf("\tWould you like to (1) encrypt or (2) decrypt a text file: ");
	scanf("%d", &operation);

        char inputFileName[100];
        char outputFileName[100];

	printf("\tEnter input file name: ");
        scanf("%s", inputFileName);

        printf("\tEnter output file name: ");
	scanf("%s", outputFileName);

	printf("\tEnter shift amount: ");
	scanf("%d", &userShiftAmount);

	printf("\tText in '%s' will be encrypted and be placed in '%s'\n", inputFileName, outputFileName);
	if (operation == 1) {
		FILE *inputFilePtr = fopen(inputFileName, "r");
        	FILE *outputFilePtr = fopen(outputFileName, "w");

		encryptFile(inputFilePtr, outputFilePtr);


//		if (inputFilePtr == NULL || outputFilePtr == NULL) {
//			printf("\tFailed to open the file(s)\n");
//			return 1;
//		}
//		else {
//			int ch;
//			while ((ch = fgetc(inputFilePtr)) != EOF) {
//				if (ch >= 'A' && ch <= 'Z') {
//					// Apply the Caesar cipher encryption
//					ch = (ch - 'A' + userShiftAmount) % 26 + 'A';
//				}
//				else if (ch >= 'a' && ch <= 'z') {
//					ch = (ch - 'a' + userShiftAmount) % 26 + 'a';
//				}
//				fputc(ch, outputFilePtr);
//			}
//		}
//		fclose(inputFilePtr);
//		fclose(outputFilePtr);
	}
	else if (operation == 2) {
		FILE *inputFilePtr = fopen(inputFileName, "r");
		FILE *outputFilePtr = fopen(outputFileName, "w");

		decryptFile(inputFilePtr, outputFilePtr);

//		if (inputFilePtr == NULL || outputFilePtr == NULL) {
//			printf("\tFailed to open the file(s)\n");
//			return 1;
//		}
//		else {
//			int ch;
//			while ((ch = fgetc(inputFilePtr)) != EOF) {
//				if (ch >= 'A' && ch <= 'Z') {
//					ch = ((ch - 'A') - userShiftAmount + 26) % 26 + 'A';
//				}
//				else if (ch >= 'a' && ch <= 'z') {
//					ch = ((ch - 'a') - userShiftAmount + 26) % 26 + 'a';
//				}
//				fputc(ch, outputFilePtr);
//			}
//		}
//		fclose(inputFilePtr);
//		fclose(outputFilePtr);
	}
	printf("\n");

	return 0;
}

void encryptFile(FILE *inputFilePtr, FILE *outputFilePtr) {
	if (inputFilePtr == NULL || outputFilePtr == NULL) {
		printf("\tFailed to open the file(s)\n");
		exit(0);
	}
	else {
		int ch;
		while ((ch = fgetc(inputFilePtr)) != EOF) {
			if (ch >= 'A' && ch <= 'Z') {
                                ch = (ch - 'A' + userShiftAmount) % 26 + 'A';
                        }
                        else if (ch >= 'a' && ch <= 'z') {
				ch = (ch - 'a' + userShiftAmount) % 26 + 'a';
                        }
                        fputc(ch, outputFilePtr);
                }
	}
	fclose(inputFilePtr);
	fclose(outputFilePtr);
	printf("\n");
}

void decryptFile(FILE *inputFilePtr, FILE *outputFilePtr) {
	if (inputFilePtr == NULL || outputFilePtr == NULL) {
		printf("\tFailed to open the file(s)\n");
		exit(0);
	}
	else {
		int ch;
		while ((ch = fgetc(inputFilePtr)) != EOF) {
			if (ch >= 'A' && ch <= 'Z') {
				ch = ((ch - 'A') - userShiftAmount + 26) % 26 + 'A';
			}
			else if (ch >= 'a' && ch <= 'z') {
				ch = ((ch - 'a') - userShiftAmount + 26) % 26 + 'a';
			}
			fputc(ch, outputFilePtr);
		}
	}
	fclose(inputFilePtr);
	fclose(outputFilePtr);
	printf("\n");
}

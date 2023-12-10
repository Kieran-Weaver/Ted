/************************************************************************/
/*									*/
/*  FieldInstructions: What to do with a field.				*/
/*									*/
/************************************************************************/

#ifndef DOC_FIELD_INSTRUCTIONS_H
#define DOC_FIELD_INSTRUCTIONS_H

#include <utilMemoryBuffer.h>

typedef struct InstructionsComponent {
	MemoryBuffer icBuffer;
	unsigned char icIsFlag;
	unsigned char icIsQuoted;
} InstructionsComponent;

typedef struct FieldInstructions {
	InstructionsComponent *fiComponents;
	int fiComponentCount;
} FieldInstructions;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

void docInitFieldInstructions(FieldInstructions *fi);
void docCleanFieldInstructions(FieldInstructions *fi);

int docCopyFieldInstructions(FieldInstructions *to,
				    const FieldInstructions *from);

int docFieldInstructionsGetComponent(const MemoryBuffer **pComponent,
					    const FieldInstructions *fi,
					    int comp);

int docAllocateComponents(FieldInstructions *fi, int n);

int docSetFieldInstructions(FieldInstructions *fi, const char *bytes,
				   int size);

int docFieldComponentInt(int *pVal, const InstructionsComponent *ic);

int docComponentIsArgFlag(const FieldInstructions *fi, int comp,
				 int flag);

int docFieldHasMergeformat(const FieldInstructions *ic, int comp);

int docComponentIsFlag(const FieldInstructions *fi, int comp, int flag);

int docFieldInstructionsAddFlag(FieldInstructions *fi, int flag);

int docStartFieldInstructions(FieldInstructions *fi,
				     const char *kindName, int kindSize);

int docFieldInstructionsAddArgFlag(FieldInstructions *fi, int flag,
					  const MemoryBuffer *valueName);

int docFieldInstructionsAddArgFlagIfSet(FieldInstructions *fi, int flag,
					       const MemoryBuffer *valueName);

int docFieldInstructionsAddComponent(FieldInstructions *fi,
					    const MemoryBuffer *mb);

int docFieldInstructionsAddFlagComponent(FieldInstructions *fi, int flag,
						const MemoryBuffer *mb);

int docFieldComponentNumberFormat(unsigned char *pNumberFormat,
					 const InstructionsComponent *ic);

int docFieldComponentCaseShift(unsigned char *pCaseShift,
				      const InstructionsComponent *ic);

int docComponentEqualsWord(const InstructionsComponent *ic,
				  const char *word, int len);

int docComponentEqualsWordNoCase(const InstructionsComponent *ic,
					const char *word, int len);

void docListFieldInstructions(int indent, const FieldInstructions *fi);

#endif /*  DOC_FIELD_INSTRUCTIONS_H  */

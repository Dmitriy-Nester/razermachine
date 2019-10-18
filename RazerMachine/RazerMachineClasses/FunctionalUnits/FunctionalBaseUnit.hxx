#ifndef _FUNCTIONALBASEUNIT_HXX_
#define _FUNCTIONALBASEUNIT_HXX_
struct FunctionalBaseUnit
{
	struct ActionUnit
	{
        size_t size;
        char *arguments;
		enum DataSize
		{
			bit0 = 0,
			bit8,
			bit16,
			bit32,
			bit64
		};
		DataSize ReturnValueType;
		enum CallType
		{
			stdcall = bit0,
			thiscall,
			fastcall,
            pascalcall //MAYBE TODO
		};
		void* action;
        void Action(char retextract[]);
	};
	private:
    char retExtract[sizeof(int32_t)]; //TODO sizeof(double)
    ActionUnit *_ActionUnit;
	FunctionalBaseUnit* NextAction;
	public:
	FunctionalBaseUnit* Action();
};
#endif
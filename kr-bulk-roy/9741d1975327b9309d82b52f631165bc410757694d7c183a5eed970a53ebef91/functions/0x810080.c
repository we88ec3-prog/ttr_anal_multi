
void FUN_00810080(void)

{
  int iVar1;
  
  iVar1 = alGetError();
  if (iVar1 != 0) {
    switch(iVar1) {
    case 0xa001:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,
                   "AL_INVALID_NAME: Invalid Name paramater passed to AL call.");
      return;
    case 0xa002:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,
                   "AL_ILLEGAL_ENUM: Invalid parameter passed to AL call.");
      return;
    case 0xa003:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,
                   "AL_INVALID_VALUE: Invalid enum parameter value.");
      return;
    case 0xa004:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,"AL_ILLEGAL_COMMAND: Illegal call.");
      return;
    case 0xa005:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,"AL_OUT_OF_MEMORY: Out of memory.");
      return;
    default:
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar1,"AL_NO_ERROR: No Error");
    }
  }
  return;
}


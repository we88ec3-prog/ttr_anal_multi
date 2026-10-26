
undefined4 FUN_00810c90(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = alGetError();
  if (iVar1 == 0) {
    return 1;
  }
  switch(iVar1) {
  case 0xa001:
    pcVar2 = "AL_INVALID_NAME: Invalid Name paramater passed to AL call.";
    break;
  case 0xa002:
    pcVar2 = "AL_ILLEGAL_ENUM: Invalid parameter passed to AL call.";
    break;
  case 0xa003:
    pcVar2 = "AL_INVALID_VALUE: Invalid enum parameter value.";
    break;
  case 0xa004:
    pcVar2 = "AL_ILLEGAL_COMMAND: Illegal call.";
    break;
  case 0xa005:
    pcVar2 = "AL_OUT_OF_MEMORY: Out of memory.";
    break;
  default:
    pcVar2 = "AL_NO_ERROR: No Error";
  }
  FUN_006edb60("OpanAL: An error occurred: %x; %s\n",iVar1,pcVar2);
  return 0;
}



void FUN_0080ffb0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined1 local_8 [4];
  
  iVar2 = param_1;
  puVar1 = (undefined4 *)(param_1 + 0x10);
  param_1 = 0;
  alGetSourcei(*puVar1,0x1015,&param_1);
  FUN_00810080();
  while (param_1 != 0) {
    param_1 = param_1 + -1;
    alSourceUnqueueBuffers(*(undefined4 *)(iVar2 + 0x10),1,local_8);
    iVar3 = alGetError();
    if (iVar3 != 0) {
      switch(iVar3) {
      case 0xa001:
        pcVar4 = "AL_INVALID_NAME: Invalid Name paramater passed to AL call.";
        break;
      case 0xa002:
        pcVar4 = "AL_ILLEGAL_ENUM: Invalid parameter passed to AL call.";
        break;
      case 0xa003:
        pcVar4 = "AL_INVALID_VALUE: Invalid enum parameter value.";
        break;
      case 0xa004:
        pcVar4 = "AL_ILLEGAL_COMMAND: Illegal call.";
        break;
      case 0xa005:
        pcVar4 = "AL_OUT_OF_MEMORY: Out of memory.";
        break;
      default:
        pcVar4 = "AL_NO_ERROR: No Error";
      }
      FUN_006edb60("OpenAL: An error occurred: %x; %s\n",iVar3,pcVar4);
    }
  }
  return;
}


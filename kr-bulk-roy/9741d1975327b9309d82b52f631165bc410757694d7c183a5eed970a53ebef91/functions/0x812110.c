
undefined4 FUN_00812110(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  undefined4 uVar4;
  
  uVar4 = 0x1101;
  if (param_4 == 2) {
    uVar4 = 0x1103;
  }
  uVar1 = *(undefined4 *)(in_ECX + 8);
  if (param_1 != 0) {
    alGetError();
    alBufferData(uVar1,uVar4,param_1,param_2,param_3);
    iVar2 = alGetError();
    if (iVar2 != 0) {
      switch(iVar2) {
      case 0xa001:
        pcVar3 = "AL_INVALID_NAME: Invalid Name paramater passed to AL call.";
        break;
      case 0xa002:
        pcVar3 = "AL_ILLEGAL_ENUM: Invalid parameter passed to AL call.";
        break;
      case 0xa003:
        pcVar3 = "AL_INVALID_VALUE: Invalid enum parameter value.";
        break;
      case 0xa004:
        pcVar3 = "AL_ILLEGAL_COMMAND: Illegal call.";
        break;
      case 0xa005:
        pcVar3 = "AL_OUT_OF_MEMORY: Out of memory.";
        break;
      default:
        pcVar3 = "AL_NO_ERROR: No Error";
      }
      FUN_006edb60("OpenAL: Failed to load data to buffer; %s",pcVar3);
      return 0;
    }
  }
  return 1;
}


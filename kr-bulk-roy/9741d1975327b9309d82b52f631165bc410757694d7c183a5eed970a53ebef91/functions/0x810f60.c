
undefined4 FUN_00810f60(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  code *pcVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int *local_14;
  uint local_c;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(in_EAX + 0x1c);
  EnterCriticalSection(lpCriticalSection);
  FUN_00542210();
  iVar2 = FUN_004d8460();
  if (local_c != *(uint *)(iVar2 + 8)) {
    do {
      if (local_14 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *local_14;
      }
      uVar3 = local_c >> 2;
      if (*(uint *)(iVar2 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(iVar2 + 8);
      }
      if (param_1 == *(int *)(*(int *)(*(int *)(iVar2 + 4) + uVar3 * 4) + (local_c & 3) * 4)) {
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      local_c = local_c + 1;
      iVar2 = FUN_004d8460();
    } while (local_c != *(uint *)(iVar2 + 8));
  }
  alDeleteSources(1,&param_1);
  iVar2 = alGetError();
  if (iVar2 != 0) {
    switch(iVar2) {
    case 0xa001:
      pcVar5 = "AL_INVALID_NAME: Invalid Name paramater passed to AL call.";
      break;
    case 0xa002:
      pcVar5 = "AL_ILLEGAL_ENUM: Invalid parameter passed to AL call.";
      break;
    case 0xa003:
      pcVar5 = "AL_INVALID_VALUE: Invalid enum parameter value.";
      break;
    case 0xa004:
      pcVar5 = "AL_ILLEGAL_COMMAND: Illegal call.";
      break;
    case 0xa005:
      pcVar5 = "AL_OUT_OF_MEMORY: Out of memory.";
      break;
    default:
      pcVar5 = "AL_NO_ERROR: No Error";
    }
    FUN_006edb60("OpanAL: An error occurred: %x; %s\n",iVar2,pcVar5);
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  param_1 = 0;
  alGenSources(1,&param_1);
  iVar2 = FUN_00810c90();
  if (iVar2 != 0) {
    FUN_006de910(&param_1);
    LeaveCriticalSection(lpCriticalSection);
    return 1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


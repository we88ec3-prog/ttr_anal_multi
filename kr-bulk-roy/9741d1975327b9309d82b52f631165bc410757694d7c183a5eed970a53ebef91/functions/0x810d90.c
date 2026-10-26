
void FUN_00810d90(void)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int *local_1c;
  uint local_14;
  undefined4 local_c;
  int *local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 7));
  if (in_EAX[5] != *in_EAX) {
    FUN_006edb60("There is unreleased sound");
  }
  local_8 = in_EAX + 1;
  FUN_00542210();
  iVar1 = FUN_004d8460();
  if (local_14 != *(uint *)(iVar1 + 8)) {
    do {
      if (local_1c == (int *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *local_1c;
      }
      uVar2 = local_14 >> 2;
      if (*(uint *)(iVar1 + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(iVar1 + 8);
      }
      local_c = *(undefined4 *)(*(int *)(*(int *)(iVar1 + 4) + uVar2 * 4) + (local_14 & 3) * 4);
      alDeleteSources(1,&local_c);
      iVar1 = alGetError();
      if (iVar1 != 0) {
        switch(iVar1) {
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
        FUN_006edb60("OpanAL: An error occurred: %x; %s\n",iVar1,pcVar3);
      }
      local_14 = local_14 + 1;
      iVar1 = FUN_004d8460();
    } while (local_14 != *(uint *)(iVar1 + 8));
  }
  FUN_007b6d70();
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 7));
  return;
}


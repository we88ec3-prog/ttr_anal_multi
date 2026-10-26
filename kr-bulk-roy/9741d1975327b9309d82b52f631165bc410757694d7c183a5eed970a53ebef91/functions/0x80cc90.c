
void FUN_0080cc90(int *param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1[1] != in_ECX) {
                    /* WARNING: Subroutine does not return */
    FUN_006edc70("SoundChannel.ReceiveAsyncMessage: pMessage->pTargetChannel != this");
  }
  if (*param_1 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0xc) != 0) {
      iVar1 = param_1[5];
      if (*(int **)(in_ECX + 8) != (int *)0x0) {
        *(int *)(in_ECX + 0x10) = param_1[2];
        *(int *)(in_ECX + 0x14) = param_1[3];
        *(int *)(in_ECX + 0x18) = param_1[4];
        *(int *)(in_ECX + 0x1c) = iVar1;
        (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1 + 2,iVar1);
      }
      FUN_0080cbe0();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 4) + 0x14) != 0) {
      *(undefined4 *)(in_ECX + 0x20) = 0;
      InterlockedDecrement((LONG *)(in_ECX + 0x24));
      return;
    }
    iVar1 = *param_1;
    iVar2 = param_1[1];
    iVar3 = param_1[2];
    iVar4 = param_1[3];
    iVar5 = param_1[4];
    iVar6 = param_1[5];
    FUN_0080a2e0(iVar1,iVar2,iVar3,iVar4,iVar5,iVar6);
    FUN_0080cd50(iVar1,iVar2,iVar3,iVar4,iVar5,iVar6);
  }
  return;
}


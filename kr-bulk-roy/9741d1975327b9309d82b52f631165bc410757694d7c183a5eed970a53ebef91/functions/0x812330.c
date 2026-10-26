
bool FUN_00812330(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    if (*(int *)(in_ECX + 0xc) != 0) {
      uVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
      alSourcei(*(undefined4 *)(in_ECX + 8),0x1009,uVar1);
      alGetError();
    }
    if (param_1 != 0) {
      FUN_00812540(in_ECX);
    }
    alSourcePlay(*(undefined4 *)(in_ECX + 8));
    iVar2 = alGetError();
    return iVar2 == 0;
  }
  return true;
}


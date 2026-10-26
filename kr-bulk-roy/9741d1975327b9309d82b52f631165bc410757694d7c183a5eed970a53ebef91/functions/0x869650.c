
undefined4 FUN_00869650(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_10;
  int iStack_c;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (*(int *)(iVar1 + 4) == *(int *)(in_ECX + 0x28)) {
    iStack_c = 0;
    if (0 < *(int *)(in_ECX + 0x30)) {
      iVar1 = 0;
      do {
        iVar3 = iStack_c;
        iVar2 = (**(code **)(*(int *)(*(int *)(in_ECX + 0x34) + 0x34 + iVar1) + 0x18))();
        if (iVar2 != 0) {
          iVar2 = *(int *)(*(int *)(in_ECX + 0x34) + iVar1 + 0x38);
          if (iVar2 == 2) {
            FUN_00791d70(param_2);
            iVar3 = iStack_c;
          }
          else if (iVar2 == 4) {
            FUN_00791b90();
          }
          else {
            FUN_00791870(param_2,&uStack_10,1);
          }
          FUN_00846260(iVar3,uStack_10);
        }
        iStack_c = iVar3 + 1;
        iVar1 = iVar1 + 0x58;
      } while (iStack_c < *(int *)(in_ECX + 0x30));
    }
    return 1;
  }
  return 0;
}


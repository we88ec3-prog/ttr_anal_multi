
void FUN_0070d8b0(int param_1,int param_2)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 in_ECX;
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x10) != param_2) {
    if (in_EAX == *(int *)(param_1 + 4)) {
      in_EAX = FUN_0070d750();
      in_ECX = extraout_ECX;
    }
    uVar1 = FUN_006ff070(in_ECX,in_EAX);
    uVar1 = FUN_006ff070(uVar1);
    uVar1 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),
                         "\'%s\' expected (to close \'%s\' at line %d)",uVar1);
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,uVar1,*(undefined4 *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) != 0x11f) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
    return;
  }
  uVar1 = FUN_006ffec0(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}


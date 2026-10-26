
void FUN_00712510(int *param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  FUN_00712360(param_2);
  if (*param_1 == 10) {
    FUN_00711fe0();
  }
  if (param_1[4] != param_1[5]) {
    iVar1 = FUN_00711d90();
    if ((iVar1 != 0) || (iVar1 = FUN_00711d90(), iVar1 != 0)) {
      if (*param_1 != 10) {
        FUN_00711ca0();
      }
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
      FUN_00713370(param_2 << 6 | 0x4002,*(undefined4 *)(*(int *)(in_EAX + 0xc) + 8));
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
      FUN_00713370(param_2 << 6 | 0x800002,*(undefined4 *)(*(int *)(in_EAX + 0xc) + 8));
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
      FUN_00711fe0();
    }
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
    FUN_00711f00();
    FUN_00711f00();
  }
  param_1[4] = -1;
  param_1[5] = -1;
  param_1[2] = param_2;
  *param_1 = 0xc;
  return;
}



void FUN_008fc710(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)param_1 + 0xa8);
  FUN_008fc680(param_1);
  if (*(int *)((int)param_1 + 0x58) != (int)param_1 + 100) {
    FUN_008b9f80(uVar1,*(int *)((int)param_1 + 0x58));
    *(undefined4 *)((int)param_1 + 0x58) = 0;
  }
  FUN_008b9f80(uVar1,*(undefined4 *)((int)param_1 + 0x4c));
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  *(undefined4 *)((int)param_1 + 0x50) = 0;
  _memset(param_1,0,0xac);
  return;
}


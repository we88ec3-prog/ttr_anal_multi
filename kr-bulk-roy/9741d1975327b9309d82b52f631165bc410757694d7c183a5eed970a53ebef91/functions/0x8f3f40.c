
void FUN_008f3f40(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_1 != (int *)0x0) {
    uVar1 = *(undefined4 *)(*param_1 + 100);
    piVar2 = param_1 + 4;
    uVar3 = 0;
    do {
      if (*piVar2 != 0) {
        if (*(code **)((&PTR_DAT_00bebb70)[*(int *)(*(int *)((int)&PTR_DAT_00bebbe0 + uVar3) + 4)] +
                      0x10) != (code *)0x0) {
          (**(code **)((&PTR_DAT_00bebb70)[*(int *)(*(int *)((int)&PTR_DAT_00bebbe0 + uVar3) + 4)] +
                      0x10))(*piVar2);
        }
        FUN_008b9f80(uVar1,*piVar2);
        *piVar2 = 0;
      }
      uVar3 = uVar3 + 4;
      piVar2 = piVar2 + 1;
    } while (uVar3 < 0xbc);
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    FUN_008b9f80(uVar1,param_1);
  }
  return;
}


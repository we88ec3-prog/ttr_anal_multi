
void FUN_008e0be0(undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = FUN_008b7f40(*(undefined4 *)(*(int *)(unaff_ESI + 0x3a0) + 0x174),0x3e80000);
  *param_1 = uVar1;
  *param_2 = *(int *)(*(int *)(unaff_ESI + 0x3a0) + 0x178) << 0x10;
  *param_3 = *(int *)(*(int *)(unaff_ESI + 0x3a0) + 0x17c) << 0x10;
  return;
}


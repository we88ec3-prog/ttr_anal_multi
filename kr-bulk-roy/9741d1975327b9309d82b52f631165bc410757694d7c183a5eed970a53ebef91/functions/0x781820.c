
void FUN_00781820(void)

{
  int *in_EAX;
  int unaff_EDI;
  undefined4 uVar1;
  int local_1c [3];
  undefined4 local_10;
  
  uVar1 = 0x781836;
  FUN_006ddcc0();
  if (*(int *)(unaff_EDI + 0x18) != 0) {
    if ((*(byte *)(*(int *)(*in_EAX + 4) + 0xc + (int)in_EAX) & 6) == 0) {
      uVar1 = 1;
      (**(code **)(**(int **)(*(int *)(*in_EAX + 4) + 0x38 + (int)in_EAX) + 0x28))(local_1c,0,0,1,1)
      ;
    }
    else {
      local_1c[0] = -1;
      local_1c[1] = 0xffffffff;
      local_1c[2] = 0;
      local_10 = 0;
    }
    FUN_00725070((local_1c[0] - *(int *)(unaff_EDI + 0x18)) + -0x20 + local_1c[2],0,0,0,0,uVar1);
    uVar1 = FUN_0087dc3d(*(undefined4 *)(unaff_EDI + 0x18));
    *(undefined4 *)(unaff_EDI + 0x1c) = uVar1;
    FUN_006ddcc0();
  }
  return;
}


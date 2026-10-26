
void FUN_007824d0(void)

{
  int in_EAX;
  int *unaff_EDI;
  int local_1c [3];
  undefined4 local_10;
  
  if ((*(byte *)(*(int *)(*unaff_EDI + 4) + 0xc + (int)unaff_EDI) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*unaff_EDI + 4) + 0x38 + (int)unaff_EDI) + 0x28))
              (local_1c,0,0,1,2);
  }
  else {
    local_1c[0] = -1;
    local_1c[1] = 0xffffffff;
    local_1c[2] = 0;
    local_10 = 0;
  }
  *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x6c) + local_1c[0] + 0x20 + local_1c[2];
  if (*(int *)(in_EAX + 0x6c) != 0) {
    FUN_00721910();
  }
  FUN_00721910();
  return;
}


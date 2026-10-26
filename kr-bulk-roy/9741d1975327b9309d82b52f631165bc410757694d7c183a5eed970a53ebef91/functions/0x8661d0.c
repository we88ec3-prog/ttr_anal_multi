
undefined4 FUN_008661d0(void)

{
  int in_EAX;
  int *unaff_ESI;
  int local_24 [3];
  undefined4 local_18;
  int *local_8;
  
  *(undefined4 *)(in_EAX + 0x24) = 1000;
  local_8 = (int *)(in_EAX + 0x28);
  *local_8 = (*(int *)(in_EAX + 0x34) - *(int *)(in_EAX + 0x30)) / 0x11c;
  if ((*(byte *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI) + 0x28))
              (local_24,0,0,1,2);
  }
  else {
    local_24[0] = -1;
    local_24[1] = 0xffffffff;
    local_24[2] = 0;
    local_18 = 0;
  }
  *(int *)(in_EAX + 0x2c) = local_24[0] + 0xc + local_24[2];
  FUN_00721910();
  FUN_00721910();
  FUN_00721910();
  return 1;
}


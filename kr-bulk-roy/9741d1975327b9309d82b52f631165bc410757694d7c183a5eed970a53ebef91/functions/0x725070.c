
void FUN_00725070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *unaff_ESI;
  uint local_1c;
  int local_18;
  uint local_14;
  
  if ((*(byte *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI) + 0x2c))
              (&local_1c,param_1,param_2,param_3,param_4,param_5,param_6,1);
    if ((local_14 + local_1c == -1) &&
       (((int)local_14 >> 0x1f) + local_18 + (uint)CARRY4(local_14,local_1c) == -1)) {
      FUN_00431a90(0);
    }
  }
  return;
}


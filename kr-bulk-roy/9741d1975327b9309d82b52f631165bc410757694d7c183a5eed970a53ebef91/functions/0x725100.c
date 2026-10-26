
void FUN_00725100(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *unaff_ESI;
  uint local_20;
  int local_1c;
  uint local_18;
  
  if ((*(byte *)(*(int *)(*unaff_ESI + 4) + 0xc + (int)unaff_ESI) & 6) == 0) {
    (**(code **)(**(int **)(*(int *)(*unaff_ESI + 4) + 0x38 + (int)unaff_ESI) + 0x28))
              (&local_20,param_1,param_2,param_3,1);
    if ((local_18 + local_20 == -1) &&
       (((int)local_18 >> 0x1f) + local_1c + (uint)CARRY4(local_18,local_20) == -1)) {
      FUN_00431a90(0);
    }
  }
  return;
}



undefined4 FUN_00705a70(int param_1)

{
  undefined4 *puVar1;
  
  FUN_00705970(1);
  puVar1 = *(undefined4 **)(param_1 + 8);
  if ((puVar1[-2] == 6) && (*(char *)(puVar1[-4] + 6) != '\0')) {
    *puVar1 = *(undefined4 *)(param_1 + 0x48);
    puVar1[1] = *(undefined4 *)(param_1 + 0x4c);
    puVar1[2] = *(undefined4 *)(param_1 + 0x50);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 1;
  }
  FUN_006f5730();
  return 1;
}


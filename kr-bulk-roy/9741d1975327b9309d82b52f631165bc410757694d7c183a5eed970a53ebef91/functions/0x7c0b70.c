
void FUN_007c0b70(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  undefined4 local_8;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  bVar1 = true;
  local_8 = 1;
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      if (((int)puVar3[5] < *(int *)(param_2 + 0x14)) ||
         (((int)puVar3[5] <= *(int *)(param_2 + 0x14) &&
          ((uint)puVar3[4] <= *(uint *)(param_2 + 0x10))))) {
        puVar2 = (undefined4 *)puVar3[2];
        bVar1 = false;
        local_8 = 0;
      }
      else {
        puVar2 = (undefined4 *)*puVar3;
        bVar1 = true;
        local_8 = 1;
      }
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if (bVar1) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar3 = (undefined4 *)FUN_007a2c90(&param_2,1,param_2);
      *unaff_ESI = *puVar3;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_008377c0();
  }
  if (((int)puVar3[5] <= *(int *)(param_2 + 0x14)) &&
     (((int)puVar3[5] < *(int *)(param_2 + 0x14) || ((uint)puVar3[4] < *(uint *)(param_2 + 0x10)))))
  {
    puVar3 = (undefined4 *)FUN_007a2c90(&param_2,local_8,param_2);
    *unaff_ESI = *puVar3;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_0089120c(param_2);
  *unaff_ESI = puVar3;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}


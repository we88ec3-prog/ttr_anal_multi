
void FUN_007a2810(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  bool bVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  bVar3 = true;
  if (*(char *)((int)puVar2[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      bVar3 = *(uint *)(param_2 + 0x10) < (uint)puVar2[4];
      if (bVar3) {
        puVar1 = (undefined4 *)*puVar2;
      }
      else {
        puVar1 = (undefined4 *)puVar2[2];
      }
    } while (*(char *)((int)puVar1 + 0x21) == '\0');
  }
  if (bVar3) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar2 = (undefined4 *)FUN_007a2c90(&param_2,1,param_2);
      *unaff_ESI = *puVar2;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_008377c0();
  }
  if ((uint)puVar2[4] < *(uint *)(param_2 + 0x10)) {
    puVar2 = (undefined4 *)FUN_007a2c90(&param_2,bVar3,param_2);
    *unaff_ESI = *puVar2;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_0089120c(param_2);
  *unaff_ESI = puVar2;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}


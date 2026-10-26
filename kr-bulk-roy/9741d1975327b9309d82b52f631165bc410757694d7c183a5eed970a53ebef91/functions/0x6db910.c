
void FUN_006db910(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  bVar1 = true;
  if (*(char *)((int)puVar3[1] + 0x31) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      bVar1 = *(short *)(param_2 + 0x10) < *(short *)(puVar3 + 4);
      if (bVar1) {
        puVar2 = (undefined4 *)*puVar3;
      }
      else {
        puVar2 = (undefined4 *)puVar3[2];
      }
    } while (*(char *)((int)puVar2 + 0x31) == '\0');
  }
  if (bVar1) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar3 = (undefined4 *)FUN_006db9e0(&param_2,1,param_2);
      *unaff_ESI = *puVar3;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_00536ea0();
  }
  if (*(short *)(puVar3 + 4) < *(short *)(param_2 + 0x10)) {
    puVar3 = (undefined4 *)FUN_006db9e0(&param_2,bVar1,param_2);
    *unaff_ESI = *puVar3;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_0089120c(param_2);
  *unaff_ESI = puVar3;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}


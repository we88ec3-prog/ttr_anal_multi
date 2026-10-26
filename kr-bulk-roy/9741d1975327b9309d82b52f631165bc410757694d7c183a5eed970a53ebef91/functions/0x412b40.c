
void FUN_00412b40(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  bool bVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  bVar3 = true;
  if (*(char *)((int)puVar2[1] + 0xf) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      bVar3 = *(ushort *)(param_2 + 0xc) < *(ushort *)(puVar2 + 3);
      if (bVar3) {
        puVar1 = (undefined4 *)*puVar2;
      }
      else {
        puVar1 = (undefined4 *)puVar2[2];
      }
    } while (*(char *)((int)puVar1 + 0xf) == '\0');
  }
  if (bVar3) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar2 = (undefined4 *)FUN_0081ded0(&param_2,1,param_2);
      *unaff_ESI = *puVar2;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_00412c10();
  }
  if (*(ushort *)(puVar2 + 3) < *(ushort *)(param_2 + 0xc)) {
    puVar2 = (undefined4 *)FUN_0081ded0(&param_2,bVar3,param_2);
    *unaff_ESI = *puVar2;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_0089120c(param_2);
  *unaff_ESI = puVar2;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}


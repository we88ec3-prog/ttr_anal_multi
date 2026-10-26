
void FUN_00820180(int param_1,int param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_ESI;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  bVar1 = true;
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar2 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar2;
      bVar1 = *(short *)(param_2 + 0xc) < *(short *)(puVar3 + 3);
      if (bVar1) {
        puVar2 = (undefined4 *)*puVar3;
      }
      else {
        puVar2 = (undefined4 *)puVar3[2];
      }
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  if (bVar1) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar3 = (undefined4 *)FUN_00518bc0(&param_2,1,param_2);
      *unaff_ESI = *puVar3;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_0081a1b0();
  }
  if (*(short *)(puVar3 + 3) < *(short *)(param_2 + 0xc)) {
    puVar3 = (undefined4 *)FUN_00518bc0(&param_2,bVar1,param_2);
    *unaff_ESI = *puVar3;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  FUN_0089120c(param_2);
  *unaff_ESI = puVar3;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}


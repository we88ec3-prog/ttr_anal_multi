
void FUN_008410e0(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *unaff_EDI;
  
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)puVar3 + 0x89);
  param_1 = CONCAT31(param_1._1_3_,1);
  while (cVar1 == '\0') {
    bVar2 = *(double *)(puVar3 + 0x14) < *(double *)(in_ECX + 0x50);
    param_1._1_3_ = (undefined3)((uint)param_1 >> 8);
    param_1 = CONCAT31(param_1._1_3_,bVar2);
    if (bVar2) {
      puVar3 = (undefined4 *)*puVar3;
    }
    else {
      puVar3 = (undefined4 *)puVar3[2];
    }
    cVar1 = *(char *)((int)puVar3 + 0x89);
  }
  puVar3 = (undefined4 *)FUN_008412d0(&param_1,param_1,in_ECX);
  *unaff_EDI = *puVar3;
  *(undefined1 *)(unaff_EDI + 1) = 1;
  return;
}


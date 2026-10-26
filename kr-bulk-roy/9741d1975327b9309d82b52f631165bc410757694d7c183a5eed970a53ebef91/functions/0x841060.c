
void FUN_00841060(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *unaff_EDI;
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)puVar2 + 0x89);
  param_1 = CONCAT31(param_1._1_3_,1);
  while (cVar1 == '\0') {
    param_1._1_3_ = (undefined3)((uint)param_1 >> 8);
    param_1 = CONCAT31(param_1._1_3_,*(double *)(in_ECX + 0x50) < *(double *)(puVar2 + 0x14));
    if (*(double *)(puVar2 + 0x14) <= *(double *)(in_ECX + 0x50)) {
      puVar2 = (undefined4 *)puVar2[2];
    }
    else {
      puVar2 = (undefined4 *)*puVar2;
    }
    cVar1 = *(char *)((int)puVar2 + 0x89);
  }
  puVar2 = (undefined4 *)FUN_008412d0(&param_1,param_1,in_ECX);
  *unaff_EDI = *puVar2;
  *(undefined1 *)(unaff_EDI + 1) = 1;
  return;
}


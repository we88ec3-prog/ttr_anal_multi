
void FUN_00853ac0(int param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)puVar2 + 0x15);
  param_1 = CONCAT31(param_1._1_3_,1);
  while (cVar1 == '\0') {
    param_1._1_3_ = (uint3)((uint)param_1 >> 8);
    if (*(float *)(in_EAX + 0xc) <= (float)puVar2[3]) {
      puVar2 = (undefined4 *)puVar2[2];
      param_1 = (uint)param_1._1_3_ << 8;
    }
    else {
      puVar2 = (undefined4 *)*puVar2;
      param_1 = CONCAT31(param_1._1_3_,1);
    }
    cVar1 = *(char *)((int)puVar2 + 0x15);
  }
  puVar2 = (undefined4 *)FUN_0044bd00(&param_1,param_1,in_EAX);
  *unaff_ESI = *puVar2;
  *(undefined1 *)(unaff_ESI + 1) = 1;
  return;
}


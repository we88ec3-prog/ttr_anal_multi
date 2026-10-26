
void FUN_004bb2b0(int *param_1)

{
  size_t _Size;
  void *pvVar1;
  char cVar2;
  int *in_EAX;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (in_EAX != param_1) {
    pvVar3 = (void *)*param_1;
    uVar5 = param_1[1] - (int)pvVar3 >> 3;
    pvVar1 = (void *)*in_EAX;
    if (uVar5 == 0) {
      if (pvVar1 != (void *)in_EAX[1]) {
        FID_conflict__memcpy(pvVar1,(void *)in_EAX[1],0);
        in_EAX[1] = (int)pvVar1;
        return;
      }
    }
    else {
      uVar6 = in_EAX[1] - (int)pvVar1 >> 3;
      if (uVar5 <= uVar6) {
        FID_conflict__memcpy(pvVar1,pvVar3,(param_1[1] - (int)pvVar3 >> 3) * 8);
        in_EAX[1] = *in_EAX + (param_1[1] - *param_1 >> 3) * 8;
        return;
      }
      if (uVar5 <= (uint)(in_EAX[2] - (int)pvVar1 >> 3)) {
        pvVar1 = (void *)((int)pvVar3 + uVar6 * 8);
        FID_conflict__memcpy((void *)*in_EAX,pvVar3,((int)pvVar1 - (int)pvVar3 >> 3) * 8);
        _Size = (param_1[1] - (int)pvVar1 >> 3) * 8;
        pvVar3 = FID_conflict__memcpy((void *)in_EAX[1],pvVar1,_Size);
        in_EAX[1] = (int)((int)pvVar3 + _Size);
        return;
      }
      if (pvVar1 != (void *)0x0) {
        FUN_0089120c(pvVar1);
      }
      cVar2 = FUN_004bb3e0();
      if (cVar2 != '\0') {
        iVar4 = FUN_004bb420(*in_EAX);
        in_EAX[1] = iVar4;
      }
    }
  }
  return;
}


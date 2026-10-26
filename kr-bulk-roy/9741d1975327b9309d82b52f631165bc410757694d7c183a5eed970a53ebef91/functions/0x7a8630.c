
void FUN_007a8630(float param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_EDI;
  float10 fVar4;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  
  if ((*(int *)(in_EAX + 0x1c) != 0) && (*(int *)(*(int *)(in_EAX + 0x1c) + 0x18) != 0)) {
    FUN_007d4480();
    *unaff_EDI = local_10;
    unaff_EDI[1] = local_c;
    unaff_EDI[2] = local_8 + param_1;
    return;
  }
  uVar1 = in_ECX[1];
  uVar2 = *in_ECX;
  fVar3 = (float)in_ECX[2];
  fVar4 = (float10)FUN_007a7100();
  *unaff_EDI = uVar2;
  unaff_EDI[1] = uVar1;
  unaff_EDI[2] = (float)(fVar4 + (float10)param_1 + (float10)fVar3);
  return;
}


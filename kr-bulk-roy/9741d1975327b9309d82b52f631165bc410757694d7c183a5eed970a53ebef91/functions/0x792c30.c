
void FUN_00792c30(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  uint unaff_EDI;
  float10 fVar3;
  float10 fVar4;
  float local_8;
  
  iVar1 = (**(code **)(*in_EAX + 0x18))();
  iVar2 = (**(code **)(*in_EAX + 0x18))();
  iVar2 = (int)(iVar1 + -1 + unaff_EDI) % iVar2;
  fVar3 = (float10)FUN_00793920(iVar2,unaff_EDI);
  local_8 = (float)fVar3;
  if (local_8 == 0.0) {
    local_8 = 1.0;
  }
  fVar3 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar2);
  fVar4 = (float10)(**(code **)(*in_EAX + 0x1c))();
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(in_EAX[6] + 0x10 + unaff_EDI * 0x18) =
       (float)(((float10)(double)fVar3 - fVar4) / (float10)local_8);
  return;
}


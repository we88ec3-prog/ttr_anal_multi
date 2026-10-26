
void FUN_00792af0(void)

{
  int *in_EAX;
  int iVar1;
  uint unaff_EDI;
  float10 fVar2;
  float10 fVar3;
  float local_8;
  
  iVar1 = (**(code **)(*in_EAX + 0x18))();
  iVar1 = (int)(iVar1 + -1 + unaff_EDI) % iVar1;
  fVar2 = (float10)FUN_00793920(iVar1,unaff_EDI);
  local_8 = (float)fVar2;
  if (local_8 == 0.0) {
    local_8 = 1.0;
  }
  fVar2 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar1);
  fVar3 = (float10)(**(code **)(*in_EAX + 0x1c))();
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= unaff_EDI) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(in_EAX[6] + 0x10 + unaff_EDI * 0x18) =
       (float)((((float10)(double)fVar2 - fVar3) + ((float10)(double)fVar2 - fVar3)) /
              (float10)local_8);
  return;
}


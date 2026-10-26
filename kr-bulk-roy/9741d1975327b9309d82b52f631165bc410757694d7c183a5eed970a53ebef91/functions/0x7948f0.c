
void FUN_007948f0(void)

{
  float fVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  
  iVar3 = in_EAX[7] - in_EAX[6];
  iVar2 = iVar3 >> 0x1f;
  if (iVar3 / 0x2c + iVar2 == iVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  fVar1 = *(float *)(in_EAX[6] + 0x10);
  fVar4 = (float10)(**(code **)(*in_EAX + 0x1c))(1);
  fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))(0);
  iVar3 = in_EAX[7] - in_EAX[6];
  iVar2 = iVar3 >> 0x1f;
  if (iVar3 / 0x2c + iVar2 == iVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(in_EAX[6] + 0x28) =
       (float)(((float10)1 - (float10)fVar1) * ((float10)(double)fVar4 - fVar5));
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x2c) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  fVar1 = *(float *)(in_EAX[6] + 0x3c);
  fVar4 = (float10)(**(code **)(*in_EAX + 0x1c))(1);
  fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))(0);
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x2c) < 2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(float *)(in_EAX[6] + 0x50) =
       (float)((float10)(double)fVar4 - ((float10)1 - (float10)fVar1) * fVar5);
  return;
}


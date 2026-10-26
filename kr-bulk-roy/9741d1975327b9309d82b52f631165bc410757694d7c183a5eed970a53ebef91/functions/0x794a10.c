
void FUN_00794a10(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  
  iVar4 = (**(code **)(*in_EAX + 0x20))(2);
  iVar5 = (**(code **)(*in_EAX + 0x20))(0);
  iVar6 = (**(code **)(*in_EAX + 0x20))(1);
  iVar7 = (**(code **)(*in_EAX + 0x20))(0);
  fVar8 = (float10)(**(code **)(*in_EAX + 0x1c))(2);
  fVar9 = (float10)(**(code **)(*in_EAX + 0x1c))(0);
  fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))(1);
  fVar11 = (float10)(**(code **)(*in_EAX + 0x1c))(0);
  iVar1 = in_EAX[6];
  iVar3 = in_EAX[7] - iVar1 >> 0x1f;
  if ((in_EAX[7] - iVar1) / 0x2c + iVar3 == iVar3) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  fVar2 = (float)((float10)(double)fVar8 - fVar9) * 0.5;
  *(float *)(iVar1 + 0x28) =
       fVar2 + ((float)((float10)(double)fVar10 - fVar11) - fVar2) * 3.0 * 0.5 +
               (1.0 - *(float *)(iVar1 + 0x10)) *
               (0.25 - (float)(iVar6 - iVar7) / ((float)(iVar4 - iVar5) + (float)(iVar4 - iVar5))) *
               (float)((float10)(double)fVar8 - fVar9);
  return;
}


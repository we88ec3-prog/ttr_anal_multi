
void FUN_00794b10(void)

{
  uint uVar1;
  float fVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  
  iVar3 = (**(code **)(*in_EAX + 0x18))();
  uVar1 = iVar3 - 1;
  iVar4 = (**(code **)(*in_EAX + 0x20))(uVar1);
  iVar5 = (**(code **)(*in_EAX + 0x20))(iVar3 + -3);
  iVar6 = (**(code **)(*in_EAX + 0x20))(iVar3 + -2);
  iVar7 = (**(code **)(*in_EAX + 0x20))(uVar1);
  fVar8 = (float10)(**(code **)(*in_EAX + 0x1c))(uVar1);
  fVar9 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar3 + -3);
  fVar10 = (float10)(**(code **)(*in_EAX + 0x1c))(uVar1);
  fVar11 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar3 + -2);
  iVar3 = in_EAX[6];
  if ((uint)((in_EAX[7] - iVar3) / 0x2c) <= uVar1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  fVar2 = (float)((float10)(double)fVar8 - fVar9) * 0.5;
  *(float *)(uVar1 * 0x2c + iVar3 + 0x24) =
       fVar2 + ((float)((float10)(double)fVar10 - fVar11) - fVar2) * 3.0 * 0.5 +
               (1.0 - *(float *)(uVar1 * 0x2c + 0x10 + iVar3)) *
               (0.25 - (float)(iVar7 - iVar6) / ((float)(iVar4 - iVar5) + (float)(iVar4 - iVar5))) *
               (float)((float10)(double)fVar8 - fVar9);
  return;
}


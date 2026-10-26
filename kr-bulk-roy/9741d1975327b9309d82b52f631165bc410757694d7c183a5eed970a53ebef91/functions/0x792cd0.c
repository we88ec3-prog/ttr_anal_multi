
uint FUN_00792cd0(void)

{
  float fVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  uint in_ECX;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float local_c;
  float local_8;
  
  iVar2 = (**(code **)(*in_EAX + 0x18))();
  if (iVar2 != 1) {
    iVar4 = in_ECX + 1;
    if (in_ECX == iVar2 - 2U) {
      fVar5 = (float10)FUN_00793920(in_ECX,iVar4);
      local_c = (float)fVar5;
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar4);
      fVar6 = (float10)(**(code **)(*in_EAX + 0x1c))();
      iVar2 = in_EAX[6];
      iVar4 = in_EAX[7] - iVar2;
      fVar1 = (float)(((float10)(double)fVar5 - fVar6) / (float10)local_c);
      if ((uint)(iVar4 / 0x18) <= in_ECX) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
    }
    else {
      fVar5 = (float10)FUN_00793920(in_ECX,iVar4);
      local_8 = (float)fVar5;
      fVar5 = (float10)FUN_00793920(iVar4,in_ECX + 2);
      local_c = (float)fVar5;
      if (local_8 == 0.0) {
        local_8 = 1.0;
      }
      if (local_c == 0.0) {
        local_c = 1.0;
      }
      fVar1 = local_8 / (local_c + local_8);
      fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar4);
      fVar6 = (float10)(**(code **)(*in_EAX + 0x1c))();
      fVar7 = (float10)(**(code **)(*in_EAX + 0x1c))(in_ECX + 2);
      fVar8 = (float10)(**(code **)(*in_EAX + 0x1c))(iVar4);
      iVar2 = in_EAX[6];
      iVar4 = in_EAX[7] - iVar2;
      if ((uint)(iVar4 / 0x18) <= in_ECX) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      fVar1 = ((fVar1 + 1.0) / local_8) * (float)((float10)(double)fVar5 - fVar6) -
              (float)((float10)(double)fVar7 - fVar8) * (fVar1 / local_c);
    }
    uVar3 = iVar4 * 0x2aaaaaab;
    *(float *)(iVar2 + 0x14 + in_ECX * 0x18) = fVar1;
    if (in_ECX == 0) {
      uVar3 = FUN_00794730(0);
    }
    return uVar3;
  }
  if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= in_ECX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(undefined4 *)(in_EAX[6] + 0x10 + in_ECX * 0x18) = 0;
  uVar3 = (in_EAX[7] - in_EAX[6]) / 0x18;
  if (in_ECX < uVar3) {
    *(undefined4 *)(in_EAX[6] + 0x14 + in_ECX * 0x18) = 0;
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid vector<T> subscript");
}


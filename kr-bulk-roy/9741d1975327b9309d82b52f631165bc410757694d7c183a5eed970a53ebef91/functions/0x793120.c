
void FUN_00793120(void)

{
  float fVar1;
  int *in_EAX;
  int iVar2;
  float fVar3;
  float in_ECX;
  undefined4 unaff_EBX;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float fVar8;
  undefined4 uStack_2c;
  float fStack_24;
  int iStack_20;
  
  (**(code **)(*in_EAX + 0x18))();
  iVar2 = (**(code **)(*in_EAX + 0x24))();
  uVar4 = iVar2 >> 7 & 7;
  iVar2 = (**(code **)(*in_EAX + 0x24))();
  fVar3 = (float)(iVar2 >> 10 & 7);
  fVar5 = (float10)FUN_00793920(unaff_EBX,in_ECX);
  fVar6 = (float10)FUN_00793920(in_ECX,uStack_2c);
  fVar1 = 0.0;
  if ((((float)fVar5 == 0.0) || ((float)fVar6 == 0.0)) ||
     (((in_ECX == 0.0 || (in_ECX == (float)(iStack_20 + -1))) &&
      ((in_EAX[3] != 3 && (in_EAX[4] != 3)))))) {
    if (fVar3 == 0.0) {
      if (in_ECX == 0.0) {
        FUN_00792cd0();
      }
      else {
        if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= (uint)in_ECX) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        *(undefined4 *)(in_EAX[6] + 0x14 + (int)in_ECX * 0x18) = 0;
      }
    }
    if (uVar4 == 0) {
      if (in_ECX == (float)(iStack_20 + -1)) {
        FUN_00792ed0();
        return;
      }
      if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= (uint)in_ECX) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      *(undefined4 *)(in_EAX[6] + 0x10 + (int)in_ECX * 0x18) = 0;
      return;
    }
  }
  else {
    if (fVar3 == 0.0) {
      if (uVar4 != 0) {
        switch(uVar4) {
        case 1:
        case 3:
        case 4:
        case 5:
          if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= (uint)in_ECX) {
                    /* WARNING: Subroutine does not return */
            FUN_0087db7d("invalid vector<T> subscript");
          }
          fVar1 = -*(float *)(in_EAX[6] + 0x10 + (int)in_ECX * 0x18);
switchD_00793206_caseD_2:
          FUN_00794770(fVar1);
          return;
        case 2:
          goto switchD_00793206_caseD_2;
        default:
          return;
        }
      }
    }
    else if (uVar4 == 0) {
      switch(fVar3) {
      case 1.4013e-45:
      case 4.2039e-45:
      case 5.60519e-45:
      case 7.00649e-45:
        if ((uint)((in_EAX[7] - in_EAX[6]) / 0x18) <= (uint)in_ECX) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        fVar1 = -*(float *)(in_EAX[6] + 0x14 + (int)in_ECX * 0x18);
switchD_00793263_caseD_2:
        FUN_00794730(fVar1);
        return;
      case 2.8026e-45:
        goto switchD_00793263_caseD_2;
      default:
        return;
      }
    }
    fVar8 = in_ECX;
    fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))();
    fStack_24 = SUB84((double)fVar5,0);
    fVar5 = (float10)(**(code **)(*in_EAX + 0x1c))(fVar3);
    fVar7 = (float10)(**(code **)(*in_EAX + 0x1c))(fVar3);
    uStack_2c = SUB84((double)fVar7,0);
    fVar7 = (float10)(**(code **)(*in_EAX + 0x1c))();
    fVar1 = ((1.0 - fStack_24) / fVar3) * in_ECX +
            (fStack_24 / (float)((float10)(double)CONCAT44(fStack_24,(float)fVar6) - fVar5)) *
            (float)((float10)(double)CONCAT44(uStack_2c,unaff_EBX) - fVar7);
    if (uVar4 == 0) {
      FUN_00794730(-fVar1);
    }
    if (fVar8 == 0.0) {
      FUN_00794770(fVar1);
      return;
    }
  }
  return;
}


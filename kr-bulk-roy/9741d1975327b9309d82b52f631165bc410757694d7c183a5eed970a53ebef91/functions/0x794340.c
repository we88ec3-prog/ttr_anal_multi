
void FUN_00794340(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int unaff_ESI;
  float10 fVar9;
  undefined4 uStack_54;
  int iStack_48;
  undefined4 uStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  fStack_40 = (float)(**(code **)(*param_1 + 0x18))();
  iVar8 = ((int)fStack_40 + -1 + in_EAX) % (int)fStack_40;
  fStack_3c = (float)iVar8;
  (**(code **)(*param_1 + 0x24))();
  iVar4 = (**(code **)(*param_1 + 0x24))();
  uVar5 = iVar4 >> 10 & 7;
  fVar9 = (float10)FUN_00793920(iVar8,in_EAX);
  fVar1 = (float)fVar9;
  fVar9 = (float10)FUN_00793920(in_EAX,uStack_54);
  fVar2 = (float)fVar9;
  if (((fVar1 == 0.0) || (fVar2 == 0.0)) ||
     (((in_EAX == 0 || (in_EAX == iStack_48 + -1)) && ((param_1[3] != 3 && (param_1[4] != 3)))))) {
    if (uVar5 == 0) {
      if (in_EAX == 0) {
        FUN_00793d80();
      }
      else {
        FUN_007948a0(0,0,0);
      }
    }
    if (unaff_ESI == 0) {
      if (in_EAX != iStack_48 + -1) {
FUN_007944ed:
        FUN_00794850(0,0,0);
        return;
      }
      FUN_00794040();
      return;
    }
  }
  else {
    if (uVar5 == 0) {
      if (unaff_ESI != 0) {
        switch(unaff_ESI) {
        case 1:
        case 3:
        case 4:
        case 5:
          pfVar6 = (float *)FUN_007947b0(in_EAX);
          fStack_40 = -*pfVar6;
          fStack_3c = -pfVar6[1];
          fStack_38 = -pfVar6[2];
          break;
        case 2:
          FUN_007948a0(0,0,0);
          return;
        default:
          goto LAB_007946f3;
        }
        goto LAB_0079466e;
      }
    }
    else if (unaff_ESI == 0) {
      switch(uVar5) {
      case 1:
      case 3:
      case 4:
      case 5:
        pfVar6 = (float *)FUN_00794800(in_EAX);
        fStack_40 = -*pfVar6;
        fStack_3c = -pfVar6[1];
        fStack_38 = -pfVar6[2];
        FUN_00794850(fStack_40,fStack_3c,fStack_38);
        return;
      case 2:
        goto FUN_007944ed;
      default:
        return;
      }
    }
    fVar3 = fVar1 / (fVar2 + fVar1);
    iVar4 = (**(code **)(*param_1 + 0x1c))(&fStack_1c,uStack_44);
    iVar8 = (**(code **)(*param_1 + 0x1c))(&fStack_30);
    fStack_40 = *(float *)(iVar8 + 4) - *(float *)(iVar4 + 4);
    fStack_3c = *(float *)(iVar8 + 8) - *(float *)(iVar4 + 8);
    pfVar6 = (float *)(**(code **)(*param_1 + 0x1c))(&fStack_2c);
    pfVar7 = (float *)(**(code **)(*param_1 + 0x1c))(&fStack_40,uStack_44);
    fVar2 = fVar3 / fVar2;
    fStack_1c = fVar2 * (*pfVar7 - *pfVar6);
    fStack_18 = (pfVar7[1] - pfVar6[1]) * fVar2;
    fStack_14 = fVar2 * (pfVar7[2] - pfVar6[2]);
    fVar1 = (1.0 - fVar3) / fVar1;
    fStack_28 = fVar1 * fStack_34;
    fStack_24 = fStack_30 * fVar1;
    fStack_20 = fVar1 * fStack_2c;
    fStack_40 = fStack_28 + fStack_1c;
    fStack_3c = fStack_24 + fStack_18;
    fStack_38 = fStack_20 + fStack_14;
    if (unaff_ESI == 0) {
      fStack_1c = -fStack_40;
      fStack_18 = -fStack_3c;
      fStack_14 = -fStack_38;
      FUN_00794850(fStack_1c,fStack_18,fStack_14);
    }
    if (uVar5 == 0) {
LAB_0079466e:
      FUN_007948a0(fStack_40,fStack_3c,fStack_38);
      return;
    }
  }
LAB_007946f3:
  return;
}


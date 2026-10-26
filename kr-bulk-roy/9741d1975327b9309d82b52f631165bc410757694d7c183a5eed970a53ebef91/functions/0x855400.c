
undefined4 FUN_00855400(int param_1)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  int in_ECX;
  float *pfStack_b0;
  int iStack_ac;
  int iStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined **ppuStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  undefined **ppuStack_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  void *pvStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  int iStack_68;
  uint uStack_64;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009204c0;
  local_14 = ExceptionList;
  uStack_64 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  iStack_68 = param_1;
  uStack_6c = 0x855437;
  FUN_008445a0();
  iStack_68 = 0;
  uStack_6c = 0xc;
  iStack_70 = in_ECX + 0x1a0;
  pvStack_74 = *(void **)(param_1 + 0x84);
  uStack_78 = 0x85544e;
  FUN_006ddcc0();
  uStack_78 = 0x855467;
  FUN_008551d0();
  uStack_84 = *(undefined4 *)(param_1 + 0x84);
  uStack_78 = 0;
  iStack_7c = 0xc;
  iStack_80 = in_ECX + 0x1ac;
  ppuStack_88 = (undefined **)0x855481;
  FUN_006ddcc0();
  ppuStack_88 = (undefined **)0x85549a;
  FUN_00855110();
  ppuStack_88 = (undefined **)0x0;
  uStack_8c = 0xc;
  iStack_90 = in_ECX + 0x1b8;
  uStack_94 = *(undefined4 *)(param_1 + 0x84);
  uStack_98 = 0x8554b4;
  FUN_006ddcc0();
  uStack_98 = 0x8554cd;
  FUN_00855050();
  uStack_98 = 0;
  ppuStack_9c = (undefined **)0xc;
  iStack_a0 = in_ECX + 0x194;
  uStack_a4 = *(undefined4 *)(param_1 + 0x84);
  iStack_a8 = 0x8554e7;
  FUN_006ddcc0();
  iStack_a8 = 0x855500;
  FUN_00855290();
  iStack_a8 = 0;
  iStack_ac = 4;
  pfVar1 = (float *)(in_ECX + 0x1c4);
  pfStack_b0 = pfVar1;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84));
  if (*pfVar1 <= 0.0) {
LAB_00855540:
    fVar2 = 0.0;
  }
  else if (1.0 <= *pfVar1) {
    fVar2 = 1.0;
  }
  else {
    if (*pfVar1 <= 0.0) goto LAB_00855540;
    fVar2 = *pfVar1;
  }
  *pfVar1 = fVar2;
  pfVar1 = (float *)(in_ECX + 0x1cc);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),pfVar1,4,0);
  if (0.0 < *pfVar1) {
    if (1.0 <= *pfVar1) {
      fVar2 = 1.0;
      goto LAB_00855590;
    }
    if (0.0 < *pfVar1) {
      fVar2 = *pfVar1;
      goto LAB_00855590;
    }
  }
  fVar2 = 0.0;
LAB_00855590:
  *pfVar1 = fVar2;
  if (*(int *)(in_ECX + 0x180) == 1) {
    pfStack_b0 = (float *)0x0;
    FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&pfStack_b0,4,0);
    iStack_ac = 0;
    if (0 < (int)pfStack_b0) {
      do {
        ppuStack_9c = gbParam::vftable;
        uStack_98 = 0;
        uStack_94 = 0;
        iStack_90 = 0;
        uStack_6c = 0;
        FUN_00868490(&ppuStack_9c);
        iStack_a8 = iStack_90;
        uVar3 = FUN_008563a0();
        uStack_6c = CONCAT31(uStack_6c._1_3_,1);
        uVar3 = FUN_00856820(uVar3);
        FUN_00856530(in_ECX + 0x184,&uStack_a4,uVar3);
        ppuStack_88 = gbParam::vftable;
        switch(uStack_84) {
        case 1:
        case 6:
        case 9:
        case 10:
        case 0xd:
          break;
        case 2:
        case 7:
        case 0xb:
          break;
        case 3:
        case 5:
        case 8:
        case 0xc:
          break;
        case 4:
          FUN_00891d3d(iStack_80);
        default:
          goto switchD_0085563b_default;
        }
        FUN_0089120c(iStack_80);
switchD_0085563b_default:
        iStack_80 = 0;
        if (iStack_7c != 0) {
          FUN_00891d3d(iStack_7c);
        }
        uStack_6c = 0xffffffff;
        ppuStack_9c = gbParam::vftable;
        switch(uStack_98) {
        case 1:
        case 6:
        case 9:
        case 10:
        case 0xd:
          break;
        case 2:
        case 7:
        case 0xb:
          break;
        case 3:
        case 5:
        case 8:
        case 0xc:
          break;
        case 4:
          FUN_00891d3d(uStack_94);
        default:
          goto switchD_00855694_default;
        }
        FUN_0089120c(uStack_94);
switchD_00855694_default:
        uStack_94 = 0;
        if (iStack_90 != 0) {
          FUN_00891d3d(iStack_90);
        }
        iStack_ac = iStack_ac + 1;
      } while (iStack_ac < (int)pfStack_b0);
    }
  }
  ExceptionList = pvStack_74;
  return 1;
}


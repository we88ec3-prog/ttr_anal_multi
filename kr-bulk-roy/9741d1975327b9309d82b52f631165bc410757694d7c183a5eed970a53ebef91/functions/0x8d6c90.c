
void FUN_008d6c90(int param_1,int *param_2)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte extraout_CL;
  byte bVar8;
  byte *_Str1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar4 = param_2;
  puVar1 = *(undefined4 **)(param_1 + 0x1e8);
  pbVar2 = (byte *)param_2[2];
  (*(code *)param_2[7])(param_2);
  _Str1 = (byte *)*param_2;
  if (pbVar2 <= _Str1) {
    param_2[3] = 3;
    return;
  }
  bVar8 = *_Str1;
  if ((9 < bVar8 - 0x30) && (bVar8 != 0x5b)) {
    if ((_Str1 + 0x11 < pbVar2) &&
       (iVar6 = _strncmp((char *)_Str1,"StandardEncoding",0x10), iVar6 == 0)) {
      *(undefined4 *)(param_1 + 0x170) = 2;
      return;
    }
    if ((_Str1 + 0xf < pbVar2) && (iVar6 = _strncmp((char *)_Str1,"ExpertEncoding",0xe), iVar6 == 0)
       ) {
      *(undefined4 *)(param_1 + 0x170) = 4;
      return;
    }
    if ((_Str1 + 0x12 < pbVar2) &&
       (iVar6 = _strncmp((char *)_Str1,"ISOLatin1Encoding",0x11), iVar6 == 0)) {
      *(undefined4 *)(param_1 + 0x170) = 3;
      return;
    }
    param_2[3] = 0xa2;
    return;
  }
  iVar6 = param_2[4];
  if (bVar8 != 0x5b) {
    local_8 = (*(code *)param_2[9])(param_2);
  }
  else {
    local_8 = 0x100;
    *param_2 = (int)(_Str1 + 1);
  }
  iVar5 = local_8;
  param_2._3_1_ = bVar8 == 0x5b;
  (*(code *)piVar4[7])(piVar4);
  if ((byte *)*piVar4 < pbVar2) {
    *(int *)(param_1 + 0x174) = iVar5;
    piVar4[0x16] = iVar5;
    uVar7 = FUN_008bc7d0(iVar6,2,0,iVar5,0,&local_c);
    *(undefined4 *)(param_1 + 0x180) = uVar7;
    if (local_c == 0) {
      uVar7 = FUN_008bc7d0(iVar6,4,0,iVar5,0,&local_c);
      *(undefined4 *)(param_1 + 0x184) = uVar7;
      if ((local_c == 0) &&
         (local_c = (**(code **)*puVar1)(piVar4 + 0x17,iVar5,iVar6), local_c == 0)) {
        iVar6 = 0;
        local_c = 0;
        if (0 < local_8) {
          do {
            (*(code *)piVar4[0x22])(piVar4 + 0x17,iVar6,".notdef",8);
            iVar6 = iVar6 + 1;
          } while (iVar6 < local_8);
        }
        local_10 = 0;
        (*(code *)piVar4[7])(piVar4);
        pbVar3 = (byte *)*piVar4;
        do {
          if (pbVar2 <= pbVar3) {
LAB_008d6f86:
            *(undefined4 *)(param_1 + 0x170) = 1;
            *piVar4 = (int)_Str1;
            return;
          }
          _Str1 = (byte *)*piVar4;
          bVar8 = *_Str1;
          if ((((bVar8 == 100) && (_Str1 + 3 < pbVar2)) && (_Str1[1] == 0x65)) &&
             ((_Str1[2] == 0x66 && (iVar6 = FUN_008d6b30(), bVar8 = extraout_CL, iVar6 != 0)))) {
            _Str1 = _Str1 + 3;
            goto LAB_008d6f86;
          }
          if (bVar8 == 0x5d) {
            _Str1 = _Str1 + 1;
            goto LAB_008d6f86;
          }
          local_14 = local_10;
          if (bVar8 - 0x30 < 10) {
            if (!param_2._3_1_) {
              local_14 = (*(code *)piVar4[9])(piVar4);
              (*(code *)piVar4[7])(piVar4);
            }
LAB_008d6f05:
            _Str1 = (byte *)*piVar4;
            if (((_Str1 + 2 < pbVar2) && (*_Str1 == 0x2f)) && (local_10 < local_8)) {
              _Str1 = _Str1 + 1;
              *piVar4 = (int)_Str1;
              (*(code *)piVar4[8])(piVar4);
              pbVar3 = (byte *)*piVar4;
              if (pbVar2 <= pbVar3) {
                return;
              }
              if (piVar4[3] != 0) {
                return;
              }
              iVar6 = (*(code *)piVar4[0x22])
                                (piVar4 + 0x17,local_14,_Str1,pbVar3 + (1 - (int)_Str1));
              piVar4[3] = iVar6;
              if (iVar6 != 0) {
                return;
              }
              local_10 = local_10 + 1;
              pbVar3[*(int *)(piVar4[0x1d] + local_14 * 4) - (int)_Str1] = 0;
            }
            else if (param_2._3_1_) {
              piVar4[3] = 2;
              return;
            }
          }
          else {
            if (param_2._3_1_) goto LAB_008d6f05;
            (*(code *)piVar4[8])(piVar4);
            if (piVar4[3] != 0) {
              return;
            }
          }
          (*(code *)piVar4[7])(piVar4);
          pbVar3 = (byte *)*piVar4;
        } while( true );
      }
    }
    piVar4[3] = local_c;
  }
  return;
}


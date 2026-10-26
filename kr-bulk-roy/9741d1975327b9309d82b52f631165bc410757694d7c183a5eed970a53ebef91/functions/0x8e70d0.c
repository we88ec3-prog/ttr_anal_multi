
void FUN_008e70d0(int param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  byte *_Str1;
  bool bVar10;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar6 = param_2;
  puVar3 = *(undefined4 **)(param_1 + 0x1e8);
  pbVar4 = (byte *)param_2[2];
  (*(code *)param_2[7])(param_2);
  _Str1 = (byte *)*param_2;
  if (pbVar4 <= _Str1) {
    param_2[3] = 3;
    return;
  }
  bVar1 = *_Str1;
  if ((9 < bVar1 - 0x30) && (bVar1 != 0x5b)) {
    if ((_Str1 + 0x11 < pbVar4) &&
       (iVar8 = _strncmp((char *)_Str1,"StandardEncoding",0x10), iVar8 == 0)) {
      *(undefined4 *)(param_1 + 0x170) = 2;
      return;
    }
    if ((_Str1 + 0xf < pbVar4) && (iVar8 = _strncmp((char *)_Str1,"ExpertEncoding",0xe), iVar8 == 0)
       ) {
      *(undefined4 *)(param_1 + 0x170) = 4;
      return;
    }
    if ((_Str1 + 0x12 < pbVar4) &&
       (iVar8 = _strncmp((char *)_Str1,"ISOLatin1Encoding",0x11), iVar8 == 0)) {
      *(undefined4 *)(param_1 + 0x170) = 3;
      return;
    }
    param_2[3] = 0xa2;
    return;
  }
  iVar8 = param_2[4];
  if (bVar1 != 0x5b) {
    local_8 = (*(code *)param_2[9])(param_2);
  }
  else {
    local_8 = 0x100;
    *param_2 = (int)(_Str1 + 1);
  }
  iVar7 = local_8;
  param_2._3_1_ = bVar1 == 0x5b;
  (*(code *)piVar6[7])(piVar6);
  if ((byte *)*piVar6 < pbVar4) {
    *(int *)(param_1 + 0x174) = iVar7;
    piVar6[0x18] = iVar7;
    uVar9 = FUN_008bc7d0(iVar8,2,0,iVar7,0,&local_c);
    *(undefined4 *)(param_1 + 0x180) = uVar9;
    if (local_c == 0) {
      uVar9 = FUN_008bc7d0(iVar8,4,0,iVar7,0,&local_c);
      *(undefined4 *)(param_1 + 0x184) = uVar9;
      if ((local_c == 0) &&
         (local_c = (**(code **)*puVar3)(piVar6 + 0x19,iVar7,iVar8), local_c == 0)) {
        iVar8 = 0;
        local_c = 0;
        if (0 < local_8) {
          do {
            (*(code *)piVar6[0x24])(piVar6 + 0x19,iVar8,".notdef",8);
            iVar8 = iVar8 + 1;
          } while (iVar8 < local_8);
        }
        local_10 = 0;
        (*(code *)piVar6[7])(piVar6);
        pbVar5 = (byte *)*piVar6;
        do {
          if (pbVar4 <= pbVar5) {
LAB_008e7455:
            *(undefined4 *)(param_1 + 0x170) = 1;
            *piVar6 = (int)_Str1;
            return;
          }
          _Str1 = (byte *)*piVar6;
          bVar1 = *_Str1;
          if (((((bVar1 == 100) && (_Str1 + 3 < pbVar4)) && (_Str1[1] == 0x65)) &&
              (_Str1[2] == 0x66)) &&
             (((((bVar2 = _Str1[3], bVar2 == 0x20 || (bVar2 == 0xd)) ||
                ((bVar2 == 10 || ((bVar2 == 9 || (bVar2 == 0xc)))))) ||
               ((bVar2 == 0 || (((bVar2 == 0x2f || (bVar2 == 0x28)) || (bVar2 == 0x29)))))) ||
              (((bVar2 == 0x3c || (bVar2 == 0x3e)) ||
               ((((bVar2 == 0x5b || ((bVar2 == 0x5d || (bVar2 == 0x7b)))) || (bVar2 == 0x7d)) ||
                (bVar2 == 0x25)))))))) {
            _Str1 = _Str1 + 3;
            goto LAB_008e7455;
          }
          if (bVar1 == 0x5d) {
            _Str1 = _Str1 + 1;
            goto LAB_008e7455;
          }
          local_14 = local_10;
          if (bVar1 - 0x30 < 10) {
            if (!param_2._3_1_) {
              local_14 = (*(code *)piVar6[9])(piVar6);
              (*(code *)piVar6[7])(piVar6);
              bVar10 = _Str1 == (byte *)*piVar6;
              _Str1 = (byte *)*piVar6;
              if (bVar10) goto LAB_008e7473;
            }
LAB_008e73d4:
            if (((_Str1 + 2 < pbVar4) && (*_Str1 == 0x2f)) && (local_10 < local_8)) {
              _Str1 = _Str1 + 1;
              *piVar6 = (int)_Str1;
              (*(code *)piVar6[8])(piVar6);
              pbVar5 = (byte *)*piVar6;
              if (pbVar4 <= pbVar5) {
                return;
              }
              if (piVar6[3] != 0) {
                return;
              }
              iVar8 = (*(code *)piVar6[0x24])
                                (piVar6 + 0x19,local_14,_Str1,pbVar5 + (1 - (int)_Str1));
              piVar6[3] = iVar8;
              if (iVar8 != 0) {
                return;
              }
              local_10 = local_10 + 1;
              pbVar5[*(int *)(piVar6[0x1f] + local_14 * 4) - (int)_Str1] = 0;
            }
            else if (param_2._3_1_) {
LAB_008e7473:
              piVar6[3] = 2;
              return;
            }
          }
          else {
            if (param_2._3_1_) goto LAB_008e73d4;
            (*(code *)piVar6[8])(piVar6);
            if (piVar6[3] != 0) {
              return;
            }
          }
          (*(code *)piVar6[7])(piVar6);
          pbVar5 = (byte *)*piVar6;
        } while( true );
      }
    }
    piVar6[3] = local_c;
  }
  return;
}


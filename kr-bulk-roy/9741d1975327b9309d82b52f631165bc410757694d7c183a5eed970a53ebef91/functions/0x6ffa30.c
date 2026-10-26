
void FUN_006ffa30(uint param_1,undefined4 *param_2)

{
  uint *in_EAX;
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_006fef80(*in_EAX);
  iVar5 = *(int *)in_EAX[0xe];
  *(int *)in_EAX[0xe] = iVar5 + -1;
  if (iVar5 == 0) {
    piVar6 = (int *)in_EAX[0xe];
    pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_8);
    if ((pbVar2 == (byte *)0x0) || (local_8 == 0)) {
      uVar4 = 0xffffffff;
    }
    else {
      piVar6[1] = (int)pbVar2;
      *piVar6 = local_8 + -1;
      uVar4 = (uint)*pbVar2;
      piVar6[1] = (int)(pbVar2 + 1);
    }
  }
  else {
    pbVar2 = *(byte **)(in_EAX[0xe] + 4);
    uVar4 = (uint)*pbVar2;
    *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
  }
  *in_EAX = uVar4;
  do {
    if (uVar4 == param_1) {
      FUN_006fef80(*in_EAX);
      iVar5 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar5 + -1;
      if (iVar5 == 0) {
        uVar4 = FUN_006fedf0();
      }
      else {
        pbVar2 = *(byte **)(in_EAX[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
      }
      *in_EAX = uVar4;
      uVar3 = FUN_006ff1b0();
      *param_2 = uVar3;
      return;
    }
    switch(*in_EAX) {
    default:
      FUN_006fef80(*in_EAX);
      iVar5 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar5 + -1;
      if (iVar5 == 0) {
        piVar6 = (int *)in_EAX[0xe];
        pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_1c);
        if (pbVar2 != (byte *)0x0) {
          bVar7 = local_1c == 0;
          iVar5 = local_1c;
          goto LAB_006ffd06;
        }
        goto LAB_006ffd17;
      }
      pbVar2 = *(byte **)(in_EAX[0xe] + 4);
      uVar4 = (uint)*pbVar2;
      *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
      goto LAB_006ffd1a;
    case 10:
    case 0xd:
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    case 0x5c:
      iVar1 = *(int *)in_EAX[0xe];
      iVar5 = 0;
      *(int *)in_EAX[0xe] = iVar1 + -1;
      if (iVar1 == 0) {
        piVar6 = (int *)in_EAX[0xe];
        pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_c);
        if ((pbVar2 == (byte *)0x0) || (local_c == 0)) {
          uVar4 = 0xffffffff;
        }
        else {
          piVar6[1] = (int)pbVar2;
          *piVar6 = local_c + -1;
          uVar4 = (uint)*pbVar2;
          piVar6[1] = (int)(pbVar2 + 1);
        }
      }
      else {
        pbVar2 = *(byte **)(in_EAX[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
      }
      break;
    case 0xffffffff:
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    *in_EAX = uVar4;
    switch(uVar4) {
    default:
      iVar1 = _isdigit(uVar4);
      if (iVar1 == 0) {
        FUN_006fef80(*in_EAX);
        iVar5 = *(int *)in_EAX[0xe];
        *(int *)in_EAX[0xe] = iVar5 + -1;
        if (iVar5 == 0) {
          piVar6 = (int *)in_EAX[0xe];
          pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_14);
          if (pbVar2 != (byte *)0x0) {
            bVar7 = local_14 == 0;
            iVar5 = local_14;
            goto LAB_006ffd06;
          }
          goto LAB_006ffd17;
        }
        pbVar2 = *(byte **)(in_EAX[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
        goto LAB_006ffd1a;
      }
      local_8 = 0;
      do {
        iVar5 = (*in_EAX - 0x30) + iVar5 * 10;
        iVar1 = *(int *)in_EAX[0xe];
        *(int *)in_EAX[0xe] = iVar1 + -1;
        if (iVar1 == 0) {
          piVar6 = (int *)in_EAX[0xe];
          pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_18);
          if ((pbVar2 == (byte *)0x0) || (local_18 == 0)) {
            uVar4 = 0xffffffff;
          }
          else {
            piVar6[1] = (int)pbVar2;
            *piVar6 = local_18 + -1;
            uVar4 = (uint)*pbVar2;
            piVar6[1] = (int)(pbVar2 + 1);
          }
        }
        else {
          pbVar2 = *(byte **)(in_EAX[0xe] + 4);
          uVar4 = (uint)*pbVar2;
          *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
        }
        local_8 = local_8 + 1;
        *in_EAX = uVar4;
      } while ((local_8 < 3) && (iVar1 = _isdigit(uVar4), iVar1 != 0));
      if (0xff < iVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130();
      }
      FUN_006fef80(iVar5);
      goto switchD_006ffb28_caseD_ffffffff;
    case 10:
    case 0xd:
      FUN_006fef80(10);
      FUN_006ff200();
      goto switchD_006ffb28_caseD_ffffffff;
    case 0x61:
      uVar3 = 7;
      break;
    case 0x62:
      uVar3 = 8;
      break;
    case 0x66:
      uVar3 = 0xc;
      break;
    case 0x6e:
      uVar3 = 10;
      break;
    case 0x72:
      uVar3 = 0xd;
      break;
    case 0x74:
      uVar3 = 9;
      break;
    case 0x76:
      uVar3 = 0xb;
      break;
    case 0xffffffff:
      goto switchD_006ffb28_caseD_ffffffff;
    }
    FUN_006fef80(uVar3);
    iVar5 = *(int *)in_EAX[0xe];
    *(int *)in_EAX[0xe] = iVar5 + -1;
    if (iVar5 == 0) {
      piVar6 = (int *)in_EAX[0xe];
      pbVar2 = (byte *)(*(code *)piVar6[2])(piVar6[4],piVar6[3],&local_10);
      if (pbVar2 != (byte *)0x0) {
        bVar7 = local_10 == 0;
        iVar5 = local_10;
LAB_006ffd06:
        if (!bVar7) {
          *piVar6 = iVar5 + -1;
          piVar6[1] = (int)pbVar2;
          uVar4 = (uint)*pbVar2;
          piVar6[1] = (int)(pbVar2 + 1);
          goto LAB_006ffd1a;
        }
      }
LAB_006ffd17:
      uVar4 = 0xffffffff;
    }
    else {
      pbVar2 = *(byte **)(in_EAX[0xe] + 4);
      uVar4 = (uint)*pbVar2;
      *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
    }
LAB_006ffd1a:
    *in_EAX = uVar4;
switchD_006ffb28_caseD_ffffffff:
    uVar4 = *in_EAX;
  } while( true );
}


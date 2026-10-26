
uint FUN_006ffec0(int *param_1)

{
  byte bVar1;
  int *piVar2;
  uint *in_EAX;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  uint uVar6;
  int local_10;
  int local_c;
  int local_8;
  
  *(undefined4 *)(in_EAX[0xf] + 4) = 0;
  do {
    switch(*in_EAX) {
    default:
      iVar3 = _isspace(*in_EAX);
      if (iVar3 == 0) {
        iVar3 = _isdigit(*in_EAX);
        if (iVar3 != 0) {
          FUN_006ff4d0();
          return 0x11c;
        }
        iVar3 = _isalpha(*in_EAX);
        if ((iVar3 != 0) || (uVar6 = *in_EAX, uVar6 == 0x5f)) {
          do {
            FUN_006fef80(*in_EAX);
            iVar3 = *(int *)in_EAX[0xe];
            *(int *)in_EAX[0xe] = iVar3 + -1;
            if (iVar3 == 0) {
              uVar6 = FUN_006fedf0();
            }
            else {
              pbVar4 = *(byte **)(in_EAX[0xe] + 4);
              uVar6 = (uint)*pbVar4;
              *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
            }
            *in_EAX = uVar6;
            iVar3 = _isalnum(uVar6);
          } while ((iVar3 != 0) || (*in_EAX == 0x5f));
          iVar3 = FUN_006ff1b0();
          if (*(byte *)(iVar3 + 6) != 0) {
            return *(byte *)(iVar3 + 6) + 0x100;
          }
          *param_1 = iVar3;
          return 0x11d;
        }
        iVar3 = *(int *)in_EAX[0xe];
        *(int *)in_EAX[0xe] = iVar3 + -1;
        if (iVar3 != 0) {
          pbVar4 = *(byte **)(in_EAX[0xe] + 4);
          bVar1 = *pbVar4;
          *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
          *in_EAX = (uint)bVar1;
          return uVar6;
        }
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 != (byte *)0x0) && (local_10 != 0)) {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          bVar1 = *pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
          *in_EAX = (uint)bVar1;
          return uVar6;
        }
        *in_EAX = 0xffffffff;
        return uVar6;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          *in_EAX = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          bVar1 = *pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
          *in_EAX = (uint)bVar1;
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        bVar1 = *pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
        *in_EAX = (uint)bVar1;
      }
      break;
    case 10:
    case 0xd:
      FUN_006ff200();
      break;
    case 0x22:
    case 0x27:
      FUN_006ffa30(*in_EAX,param_1);
      return 0x11e;
    case 0x2d:
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_8);
        if ((pbVar4 == (byte *)0x0) || (local_8 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_8 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 != 0x2d) {
        return 0x2d;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_c);
        if ((pbVar4 == (byte *)0x0) || (local_c == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_c + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 == 0x5b) {
        iVar3 = FUN_006ff660();
        *(undefined4 *)(in_EAX[0xf] + 4) = 0;
        if (iVar3 < 0) goto LAB_006fffd2;
        FUN_006ff760(0,iVar3);
        *(undefined4 *)(in_EAX[0xf] + 4) = 0;
      }
      else {
LAB_006fffd2:
        uVar6 = *in_EAX;
        while (((uVar6 != 10 && (*in_EAX != 0xd)) && (*in_EAX != 0xffffffff))) {
          iVar3 = *(int *)in_EAX[0xe];
          *(int *)in_EAX[0xe] = iVar3 + -1;
          if (iVar3 == 0) {
            uVar6 = FUN_006fedf0();
          }
          else {
            pbVar4 = *(byte **)(in_EAX[0xe] + 4);
            uVar6 = (uint)*pbVar4;
            *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
          }
          *in_EAX = uVar6;
        }
      }
      break;
    case 0x2e:
      FUN_006fef80(*in_EAX);
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      pcVar5 = _strchr(".",uVar6);
      if ((pcVar5 != (char *)0x0) && (iVar3 = FUN_006ff3a0(), iVar3 != 0)) {
        pcVar5 = _strchr(".",*in_EAX);
        if ((pcVar5 != (char *)0x0) && (iVar3 = FUN_006ff3a0(), iVar3 != 0)) {
          return 0x117;
        }
        return 0x116;
      }
      iVar3 = _isdigit(*in_EAX);
      if (iVar3 == 0) {
        return 0x2e;
      }
      FUN_006ff4d0();
      return 0x11c;
    case 0x3c:
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 != 0x3d) {
        return 0x3c;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 != 0) {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        bVar1 = *pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
        *in_EAX = (uint)bVar1;
        return 0x11a;
      }
      piVar2 = (int *)in_EAX[0xe];
      pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
      if ((pbVar4 != (byte *)0x0) && (local_10 != 0)) {
        piVar2[1] = (int)pbVar4;
        *piVar2 = local_10 + -1;
        bVar1 = *pbVar4;
        piVar2[1] = (int)(pbVar4 + 1);
        *in_EAX = (uint)bVar1;
        return 0x11a;
      }
      *in_EAX = 0xffffffff;
      return 0x11a;
    case 0x3d:
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 != 0x3d) {
        return 0x3d;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 != 0) {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        bVar1 = *pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
        *in_EAX = (uint)bVar1;
        return 0x118;
      }
      piVar2 = (int *)in_EAX[0xe];
      pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
      if ((pbVar4 != (byte *)0x0) && (local_10 != 0)) {
        piVar2[1] = (int)pbVar4;
        *piVar2 = local_10 + -1;
        bVar1 = *pbVar4;
        piVar2[1] = (int)(pbVar4 + 1);
        *in_EAX = (uint)bVar1;
        return 0x118;
      }
      *in_EAX = 0xffffffff;
      return 0x118;
    case 0x3e:
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 != 0x3d) {
        return 0x3e;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 != 0) {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        bVar1 = *pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
        *in_EAX = (uint)bVar1;
        return 0x119;
      }
      piVar2 = (int *)in_EAX[0xe];
      pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
      if ((pbVar4 != (byte *)0x0) && (local_10 != 0)) {
        piVar2[1] = (int)pbVar4;
        *piVar2 = local_10 + -1;
        bVar1 = *pbVar4;
        piVar2[1] = (int)(pbVar4 + 1);
        *in_EAX = (uint)bVar1;
        return 0x119;
      }
      *in_EAX = 0xffffffff;
      return 0x119;
    case 0x5b:
      iVar3 = FUN_006ff660();
      if (-1 < iVar3) {
        FUN_006ff760(param_1,iVar3);
        return 0x11e;
      }
      if (iVar3 == -1) {
        return 0x5b;
      }
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    case 0x7e:
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
        if ((pbVar4 == (byte *)0x0) || (local_10 == 0)) {
          uVar6 = 0xffffffff;
        }
        else {
          piVar2[1] = (int)pbVar4;
          *piVar2 = local_10 + -1;
          uVar6 = (uint)*pbVar4;
          piVar2[1] = (int)(pbVar4 + 1);
        }
      }
      else {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        uVar6 = (uint)*pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
      }
      *in_EAX = uVar6;
      if (uVar6 != 0x3d) {
        return 0x7e;
      }
      iVar3 = *(int *)in_EAX[0xe];
      *(int *)in_EAX[0xe] = iVar3 + -1;
      if (iVar3 != 0) {
        pbVar4 = *(byte **)(in_EAX[0xe] + 4);
        bVar1 = *pbVar4;
        *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
        *in_EAX = (uint)bVar1;
        return 0x11b;
      }
      piVar2 = (int *)in_EAX[0xe];
      pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_10);
      if ((pbVar4 != (byte *)0x0) && (local_10 != 0)) {
        piVar2[1] = (int)pbVar4;
        *piVar2 = local_10 + -1;
        bVar1 = *pbVar4;
        piVar2[1] = (int)(pbVar4 + 1);
        *in_EAX = (uint)bVar1;
        return 0x11b;
      }
      *in_EAX = 0xffffffff;
      return 0x11b;
    case 0xffffffff:
      return 0x11f;
    }
  } while( true );
}


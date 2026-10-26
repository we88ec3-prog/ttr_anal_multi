
void FUN_006ff760(undefined4 *param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  uint *in_EAX;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_c;
  int local_8;
  
  FUN_006fef80(*in_EAX);
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
  if ((uVar6 == 10) || (uVar6 == 0xd)) {
    FUN_006ff200();
  }
  do {
    switch(*in_EAX) {
    default:
      if (param_1 == (undefined4 *)0x0) {
        iVar3 = *(int *)in_EAX[0xe];
        *(int *)in_EAX[0xe] = iVar3 + -1;
        if (iVar3 != 0) {
          pbVar4 = *(byte **)(in_EAX[0xe] + 4);
          bVar1 = *pbVar4;
          *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
          *in_EAX = (uint)bVar1;
          break;
        }
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_c);
        iVar3 = local_c;
      }
      else {
        FUN_006fef80(*in_EAX);
        iVar3 = *(int *)in_EAX[0xe];
        *(int *)in_EAX[0xe] = iVar3 + -1;
        if (iVar3 != 0) {
          pbVar4 = *(byte **)(in_EAX[0xe] + 4);
          bVar1 = *pbVar4;
          *(byte **)(in_EAX[0xe] + 4) = pbVar4 + 1;
          *in_EAX = (uint)bVar1;
          break;
        }
        piVar2 = (int *)in_EAX[0xe];
        pbVar4 = (byte *)(*(code *)piVar2[2])(piVar2[4],piVar2[3],&local_8);
        iVar3 = local_8;
      }
      if ((pbVar4 == (byte *)0x0) || (iVar3 == 0)) {
        *in_EAX = 0xffffffff;
      }
      else {
        *piVar2 = iVar3 + -1;
        piVar2[1] = (int)pbVar4;
        bVar1 = *pbVar4;
        piVar2[1] = (int)(pbVar4 + 1);
        *in_EAX = (uint)bVar1;
      }
      break;
    case 10:
    case 0xd:
      FUN_006fef80(10);
      FUN_006ff200();
      if (param_1 == (undefined4 *)0x0) {
        *(undefined4 *)(in_EAX[0xf] + 4) = 0;
      }
      break;
    case 0x5b:
      iVar3 = FUN_006ff660();
      if (iVar3 == param_2) {
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
        if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130();
        }
      }
      break;
    case 0x5d:
      iVar3 = FUN_006ff660();
      if (iVar3 == param_2) {
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
        if (param_1 != (undefined4 *)0x0) {
          uVar5 = FUN_006ff1b0();
          *param_1 = uVar5;
        }
        return;
      }
      break;
    case 0xffffffff:
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
  } while( true );
}


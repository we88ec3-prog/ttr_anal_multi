
uint FUN_008fb0b0(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int *in_EAX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (((in_EAX == (int *)0x0) || ((uint *)in_EAX[7] == (uint *)0x0)) || (*in_EAX == 0)) {
    return 0xfffffffe;
  }
  uVar3 = *(uint *)in_EAX[7];
  uVar4 = 0xfffffffb;
  uVar5 = (param_1 != 4) - 1 & 0xfffffffb;
  if (0xd < uVar3) {
    return 0xfffffffe;
  }
  do {
    switch((&switchD_008fb0f7::switchdataD_008fb444)[uVar3]) {
    case (undefined *)0x8fb0fe:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      bVar1 = *(byte *)*in_EAX;
      *(uint *)(in_EAX[7] + 4) = (uint)bVar1;
      *in_EAX = *in_EAX + 1;
      if ((bVar1 & 0xf) == 8) {
        puVar2 = (undefined4 *)in_EAX[7];
        if (((uint)puVar2[1] >> 4) + 8 <= (uint)puVar2[4]) {
          *puVar2 = 1;
          uVar4 = uVar5;
          goto switchD_008fb0f7_caseD_8fb16d;
        }
        *puVar2 = 0xd;
        in_EAX[6] = (int)"invalid window size";
        goto LAB_008fb301;
      }
      *(undefined4 *)in_EAX[7] = 0xd;
      in_EAX[6] = (int)"unknown compression method";
      *(undefined4 *)(in_EAX[7] + 4) = 5;
      uVar4 = uVar5;
      break;
    case (undefined *)0x8fb16d:
switchD_008fb0f7_caseD_8fb16d:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      bVar1 = *(byte *)*in_EAX;
      *in_EAX = (int)((byte *)*in_EAX + 1);
      if ((*(int *)(in_EAX[7] + 4) * 0x100 + (uint)bVar1) % 0x1f == 0) {
        if ((bVar1 & 0x20) != 0) {
          *(undefined4 *)in_EAX[7] = 2;
          uVar4 = uVar5;
          goto switchD_008fb0f7_caseD_8fb32e;
        }
        *(undefined4 *)in_EAX[7] = 7;
        uVar4 = uVar5;
        break;
      }
      *(undefined4 *)in_EAX[7] = 0xd;
      in_EAX[6] = (int)"incorrect header check";
      goto LAB_008fb301;
    case (undefined *)0x8fb1d1:
      uVar3 = FUN_008fa5e0(uVar4);
      if (uVar3 == 0xfffffffd) {
        *(undefined4 *)in_EAX[7] = 0xd;
        *(undefined4 *)(in_EAX[7] + 4) = 0;
        uVar4 = 0xfffffffd;
      }
      else {
        if (uVar3 == 0) {
          uVar3 = uVar5;
        }
        if (uVar3 != 1) {
          return uVar3;
        }
        FUN_008fa4d0();
        puVar2 = (undefined4 *)in_EAX[7];
        if (puVar2[3] == 0) {
          *puVar2 = 8;
          uVar4 = uVar5;
          goto switchD_008fb0f7_caseD_8fb23d;
        }
        *puVar2 = 0xc;
        uVar4 = uVar5;
      }
      break;
    case (undefined *)0x8fb23d:
switchD_008fb0f7_caseD_8fb23d:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      *(uint *)(in_EAX[7] + 8) = (uint)*(byte *)*in_EAX << 0x18;
      *in_EAX = *in_EAX + 1;
      *(undefined4 *)in_EAX[7] = 9;
      uVar4 = uVar5;
    case (undefined *)0x8fb26a:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX * 0x10000;
      *in_EAX = *in_EAX + 1;
      *(undefined4 *)in_EAX[7] = 10;
      uVar4 = uVar5;
switchD_008fb0f7_caseD_8fb297:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX * 0x100;
      *in_EAX = *in_EAX + 1;
      *(undefined4 *)in_EAX[7] = 0xb;
      uVar4 = uVar5;
switchD_008fb0f7_caseD_8fb2c4:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX;
      puVar2 = (undefined4 *)in_EAX[7];
      *in_EAX = *in_EAX + 1;
      if (puVar2[1] == puVar2[2]) {
        *(undefined4 *)in_EAX[7] = 0xc;
switchD_008fb0f7_caseD_8fb41f:
        return 1;
      }
      *puVar2 = 0xd;
      in_EAX[6] = (int)"incorrect data check";
LAB_008fb301:
      *(undefined4 *)(in_EAX[7] + 4) = 5;
      uVar4 = uVar5;
      break;
    case (undefined *)0x8fb297:
      goto switchD_008fb0f7_caseD_8fb297;
    case (undefined *)0x8fb2c4:
      goto switchD_008fb0f7_caseD_8fb2c4;
    case (undefined *)0x8fb32e:
switchD_008fb0f7_caseD_8fb32e:
      if (in_EAX[1] == 0) {
        return uVar4;
      }
      in_EAX[2] = in_EAX[2] + 1;
      in_EAX[1] = in_EAX[1] + -1;
      *(uint *)(in_EAX[7] + 8) = (uint)*(byte *)*in_EAX << 0x18;
      *in_EAX = *in_EAX + 1;
      *(undefined4 *)in_EAX[7] = 3;
      uVar4 = uVar5;
    case (undefined *)0x8fb35b:
      if (in_EAX[1] != 0) {
        in_EAX[2] = in_EAX[2] + 1;
        in_EAX[1] = in_EAX[1] + -1;
        *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX * 0x10000;
        *in_EAX = *in_EAX + 1;
        *(undefined4 *)in_EAX[7] = 4;
        uVar4 = uVar5;
switchD_008fb0f7_caseD_8fb388:
        if (in_EAX[1] != 0) {
          in_EAX[2] = in_EAX[2] + 1;
          in_EAX[1] = in_EAX[1] + -1;
          *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX * 0x100;
          *in_EAX = *in_EAX + 1;
          *(undefined4 *)in_EAX[7] = 5;
          uVar4 = uVar5;
switchD_008fb0f7_caseD_8fb3b1:
          if (in_EAX[1] != 0) {
            in_EAX[2] = in_EAX[2] + 1;
            in_EAX[1] = in_EAX[1] + -1;
            *(int *)(in_EAX[7] + 8) = *(int *)(in_EAX[7] + 8) + (uint)*(byte *)*in_EAX;
            *in_EAX = *in_EAX + 1;
            in_EAX[0xc] = ((undefined4 *)in_EAX[7])[2];
            *(undefined4 *)in_EAX[7] = 6;
            return 2;
          }
        }
      }
      return uVar4;
    case (undefined *)0x8fb388:
      goto switchD_008fb0f7_caseD_8fb388;
    case (undefined *)0x8fb3b1:
      goto switchD_008fb0f7_caseD_8fb3b1;
    case (undefined *)0x8fb3e7:
      *(undefined4 *)in_EAX[7] = 0xd;
      in_EAX[6] = (int)"need dictionary";
      *(undefined4 *)(in_EAX[7] + 4) = 0;
      return 0xfffffffe;
    case (undefined *)0x8fb41f:
      goto switchD_008fb0f7_caseD_8fb41f;
    case (undefined *)0x8fb42b:
      return 0xfffffffd;
    }
    uVar3 = *(uint *)in_EAX[7];
    if (0xd < uVar3) {
      return 0xfffffffe;
    }
  } while( true );
}


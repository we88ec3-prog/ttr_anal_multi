
char * FUN_007290d0(char *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int *in_EAX;
  int *piVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  uint _Size;
  char *local_8;
  
  pcVar2 = param_1;
  if ((param_1 != (char *)0x0) && (0 < param_2)) {
    do {
      param_2 = param_2 + -1;
      if (((param_2 < 1) ||
          (((in_EAX == (int *)0x0 || ((char)in_EAX[0x17] != 'r')) ||
           (iVar5 = in_EAX[0xe], iVar5 == -3)))) || ((iVar5 == -1 || (iVar5 == 1)))) break;
      in_EAX[3] = (int)param_1;
      in_EAX[4] = 1;
      local_8 = param_1;
      if (in_EAX[0x1b] == -1) {
LAB_0072916e:
        pcVar10 = local_8;
        pcVar9 = local_8;
        if (in_EAX[4] != 0) {
          do {
            if (in_EAX[0x16] != 0) {
              _Size = in_EAX[1];
              if ((uint)in_EAX[4] < (uint)in_EAX[1]) {
                _Size = in_EAX[4];
              }
              if (_Size != 0) {
                FID_conflict__memcpy((void *)in_EAX[3],(void *)*in_EAX,_Size);
                *in_EAX = *in_EAX + _Size;
                in_EAX[4] = in_EAX[4] - _Size;
                local_8 = local_8 + _Size;
                in_EAX[1] = in_EAX[1] - _Size;
                in_EAX[3] = (int)local_8;
              }
              if (in_EAX[4] != 0) {
                sVar4 = _fread(local_8,1,in_EAX[4],(FILE *)in_EAX[0x10]);
                in_EAX[4] = in_EAX[4] - sVar4;
              }
              iVar5 = 1 - in_EAX[4];
              in_EAX[0x19] = in_EAX[0x19] + iVar5;
              in_EAX[0x1a] = in_EAX[0x1a] + iVar5;
              if (iVar5 == 0) {
                in_EAX[0xf] = 1;
              }
              goto LAB_0072936a;
            }
            pcVar10 = pcVar9;
            if ((in_EAX[1] == 0) && (in_EAX[0xf] == 0)) {
              piVar3 = __errno();
              *piVar3 = 0;
              sVar4 = _fread((void *)in_EAX[0x11],1,0x4000,(FILE *)in_EAX[0x10]);
              in_EAX[1] = sVar4;
              if (sVar4 == 0) {
                in_EAX[0xf] = 1;
                iVar5 = _ferror((FILE *)in_EAX[0x10]);
                if (iVar5 != 0) {
                  in_EAX[0xe] = -1;
                  break;
                }
              }
              *in_EAX = in_EAX[0x11];
            }
            in_EAX[0x19] = in_EAX[0x19] + in_EAX[1];
            in_EAX[0x1a] = in_EAX[0x1a] + in_EAX[4];
            iVar5 = FUN_007274b0();
            in_EAX[0x19] = in_EAX[0x19] - in_EAX[1];
            in_EAX[0x1a] = in_EAX[0x1a] - in_EAX[4];
            in_EAX[0xe] = iVar5;
            if (iVar5 == 1) {
              pcVar10 = (char *)in_EAX[3];
              if (pcVar9 == (char *)0x0) {
                iVar5 = 0;
              }
              else {
                iVar5 = FUN_0072b700((int)pcVar10 - (int)pcVar9);
              }
              in_EAX[0x13] = iVar5;
              iVar5 = FUN_00728be0();
              iVar6 = FUN_00728be0();
              iVar7 = FUN_00728be0();
              iVar8 = FUN_00728be0();
              if (iVar8 == -1) {
                in_EAX[0xe] = -3;
              }
              if (iVar8 * 0x1000000 + iVar5 + iVar6 * 0x100 + iVar7 * 0x10000 != in_EAX[0x13]) {
                in_EAX[0xe] = -3;
                break;
              }
              FUN_00729720();
              FUN_00728c50();
              if (in_EAX[0xe] != 0) break;
              FUN_007272b0();
              iVar5 = FUN_0072b6e0(0,0);
              in_EAX[0x13] = iVar5;
            }
            if (((in_EAX[0xe] != 0) || (in_EAX[0xf] != 0)) || (pcVar9 = pcVar10, in_EAX[4] == 0))
            break;
          } while( true );
        }
        if (pcVar10 == (char *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_0072b700(in_EAX[3] - (int)pcVar10);
        }
        in_EAX[0x13] = iVar5;
        if ((in_EAX[4] == 1) && ((in_EAX[0xe] == -3 || (in_EAX[0xe] == -1)))) break;
        iVar5 = 1 - in_EAX[4];
LAB_0072936a:
        if (iVar5 != 1) break;
      }
      else {
        *param_1 = (char)in_EAX[0x1b];
        in_EAX[3] = in_EAX[3] + 1;
        in_EAX[4] = in_EAX[4] + -1;
        in_EAX[0x1a] = in_EAX[0x1a] + 1;
        local_8 = param_1 + 1;
        in_EAX[0x1b] = -1;
        if (in_EAX[0x1c] == 0) goto LAB_0072916e;
        in_EAX[0xe] = 1;
      }
      cVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\n');
    *param_1 = '\0';
    if (pcVar2 != param_1) {
      return pcVar2;
    }
    if (param_2 < 1) {
      return pcVar2;
    }
  }
  return (char *)0x0;
}


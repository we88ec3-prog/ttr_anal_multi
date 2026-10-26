
int FUN_00728e60(int param_1)

{
  undefined1 *in_EAX;
  int *piVar1;
  size_t sVar2;
  int iVar3;
  int *in_ECX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint _Size;
  undefined1 *local_8;
  
  if ((in_ECX == (int *)0x0) || ((char)in_ECX[0x17] != 'r')) {
    return -2;
  }
  iVar3 = in_ECX[0xe];
  if ((iVar3 != -3) && (iVar3 != -1)) {
    if (iVar3 == 1) {
      return 0;
    }
    in_ECX[3] = (int)in_EAX;
    in_ECX[4] = param_1;
    local_8 = in_EAX;
    if ((param_1 != 0) && (in_ECX[0x1b] != -1)) {
      *in_EAX = (char)in_ECX[0x1b];
      in_ECX[3] = in_ECX[3] + 1;
      in_ECX[4] = in_ECX[4] + -1;
      in_ECX[0x1a] = in_ECX[0x1a] + 1;
      local_8 = in_EAX + 1;
      in_ECX[0x1b] = -1;
      if (in_ECX[0x1c] != 0) {
        in_ECX[0xe] = 1;
        return 1;
      }
    }
    puVar5 = local_8;
    if (in_ECX[4] != 0) {
      do {
        if (in_ECX[0x16] != 0) {
          _Size = in_ECX[1];
          if ((uint)in_ECX[4] < (uint)in_ECX[1]) {
            _Size = in_ECX[4];
          }
          if (_Size != 0) {
            FID_conflict__memcpy((void *)in_ECX[3],(void *)*in_ECX,_Size);
            *in_ECX = *in_ECX + _Size;
            in_ECX[4] = in_ECX[4] - _Size;
            local_8 = local_8 + _Size;
            in_ECX[1] = in_ECX[1] - _Size;
            in_ECX[3] = (int)local_8;
          }
          if (in_ECX[4] != 0) {
            sVar2 = _fread(local_8,1,in_ECX[4],(FILE *)in_ECX[0x10]);
            in_ECX[4] = in_ECX[4] - sVar2;
          }
          param_1 = param_1 - in_ECX[4];
          in_ECX[0x19] = in_ECX[0x19] + param_1;
          in_ECX[0x1a] = in_ECX[0x1a] + param_1;
          if (param_1 != 0) {
            return param_1;
          }
          in_ECX[0xf] = 1;
          return 0;
        }
        if ((in_ECX[1] == 0) && (in_ECX[0xf] == 0)) {
          piVar1 = __errno();
          *piVar1 = 0;
          sVar2 = _fread((void *)in_ECX[0x11],1,0x4000,(FILE *)in_ECX[0x10]);
          in_ECX[1] = sVar2;
          if (sVar2 == 0) {
            in_ECX[0xf] = 1;
            iVar3 = _ferror((FILE *)in_ECX[0x10]);
            if (iVar3 != 0) {
              in_ECX[0xe] = -1;
              break;
            }
          }
          *in_ECX = in_ECX[0x11];
        }
        in_ECX[0x19] = in_ECX[0x19] + in_ECX[1];
        in_ECX[0x1a] = in_ECX[0x1a] + in_ECX[4];
        iVar3 = FUN_007274b0();
        in_ECX[0x19] = in_ECX[0x19] - in_ECX[1];
        in_ECX[0x1a] = in_ECX[0x1a] - in_ECX[4];
        in_ECX[0xe] = iVar3;
        puVar4 = puVar5;
        if (iVar3 == 1) {
          puVar4 = (undefined1 *)in_ECX[3];
          if (puVar5 == (undefined1 *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_0072b700((int)puVar4 - (int)puVar5);
          }
          in_ECX[0x13] = iVar3;
          iVar3 = FUN_00729720();
          puVar5 = puVar4;
          if (iVar3 != in_ECX[0x13]) {
            in_ECX[0xe] = -3;
            break;
          }
          FUN_00729720();
          FUN_00728c50();
          if (in_ECX[0xe] != 0) break;
          FUN_007272b0();
          iVar3 = FUN_0072b6e0(0,0);
          in_ECX[0x13] = iVar3;
        }
        puVar5 = puVar4;
        if (((in_ECX[0xe] != 0) || (in_ECX[0xf] != 0)) || (in_ECX[4] == 0)) break;
      } while( true );
    }
    iVar3 = FUN_0072b6e0(in_ECX[0x13],in_ECX[3] - (int)puVar5);
    in_ECX[0x13] = iVar3;
    if ((param_1 != in_ECX[4]) || ((in_ECX[0xe] != -3 && (in_ECX[0xe] != -1)))) {
      return param_1 - in_ECX[4];
    }
  }
  return -1;
}


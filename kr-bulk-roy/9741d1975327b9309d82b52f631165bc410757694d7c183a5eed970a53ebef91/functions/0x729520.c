
int FUN_00729520(int param_1)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined4 *unaff_EDI;
  
  if ((((unaff_EDI == (undefined4 *)0x0) || (in_ECX == 2)) || (unaff_EDI[0xe] == -1)) ||
     (unaff_EDI[0xe] == -3)) {
    return -1;
  }
  if (*(char *)(unaff_EDI + 0x17) == 'w') {
    if (in_ECX == 0) {
      param_1 = param_1 - unaff_EDI[0x19];
    }
    if (-1 < param_1) {
      if (unaff_EDI[0x11] == 0) {
        pvVar1 = _malloc(0x4000);
        unaff_EDI[0x11] = pvVar1;
        if (pvVar1 == (void *)0x0) {
          return -1;
        }
        _memset(pvVar1,0,0x4000);
      }
      while( true ) {
        if (param_1 < 1) {
          return unaff_EDI[0x19];
        }
        iVar2 = FUN_007293a0(unaff_EDI[0x11]);
        if (iVar2 == 0) break;
        param_1 = param_1 - iVar2;
      }
    }
  }
  else {
    if (in_ECX == 1) {
      param_1 = param_1 + unaff_EDI[0x1a];
    }
    if (-1 < param_1) {
      if (unaff_EDI[0x16] == 0) {
        if (param_1 < (int)unaff_EDI[0x1a]) {
          iVar2 = FUN_007296a0();
          if (iVar2 < 0) {
            return -1;
          }
        }
        else {
          param_1 = param_1 - unaff_EDI[0x1a];
        }
        if (param_1 != 0) {
          if (unaff_EDI[0x12] == 0) {
            pvVar1 = _malloc(0x4000);
            unaff_EDI[0x12] = pvVar1;
            if (pvVar1 == (void *)0x0) {
              return -1;
            }
          }
          if (unaff_EDI[0x1b] != -1) {
            unaff_EDI[0x1a] = unaff_EDI[0x1a] + 1;
            param_1 = param_1 + -1;
            unaff_EDI[0x1b] = 0xffffffff;
            if (unaff_EDI[0x1c] != 0) {
              unaff_EDI[0xe] = 1;
            }
          }
          for (; 0 < param_1; param_1 = param_1 - iVar2) {
            iVar2 = 0x4000;
            if (param_1 < 0x4000) {
              iVar2 = param_1;
            }
            iVar2 = FUN_00728e60(iVar2);
            if (iVar2 < 1) {
              return -1;
            }
          }
        }
        return unaff_EDI[0x1a];
      }
      unaff_EDI[0x1b] = 0xffffffff;
      unaff_EDI[1] = 0;
      *unaff_EDI = unaff_EDI[0x11];
      iVar2 = _fseek((FILE *)unaff_EDI[0x10],param_1,0);
      if (-1 < iVar2) {
        unaff_EDI[0x1a] = param_1;
        unaff_EDI[0x19] = param_1;
        return param_1;
      }
    }
  }
  return -1;
}


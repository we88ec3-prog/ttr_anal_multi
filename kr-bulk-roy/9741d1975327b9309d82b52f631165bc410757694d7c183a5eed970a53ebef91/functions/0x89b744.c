
/* Library Function - Single Match
    __splitpath_helper
   
   Library: Visual Studio 2010 Release */

undefined4
__splitpath_helper(uchar *param_1,uchar *param_2,uint param_3,uchar *param_4,uint param_5,
                  uchar *param_6,uint param_7,uchar *param_8,uint param_9)

{
  uchar uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uchar *_Src;
  uchar *puVar5;
  uchar *puVar6;
  undefined4 uVar7;
  
  bVar2 = false;
  if (param_1 != (uchar *)0x0) {
    if (param_2 == (uchar *)0x0) {
      if (param_3 == 0) {
LAB_0089b76e:
        if (param_4 == (uchar *)0x0) {
          if (param_5 == 0) {
LAB_0089b77f:
            if (param_6 == (uchar *)0x0) {
              if (param_7 == 0) {
LAB_0089b790:
                if (param_8 == (uchar *)0x0) {
                  if (param_9 == 0) {
LAB_0089b79a:
                    iVar3 = 1;
                    puVar5 = param_1;
                    do {
                      if (*puVar5 == '\0') break;
                      iVar3 = iVar3 + -1;
                      puVar5 = puVar5 + 1;
                    } while (iVar3 != 0);
                    if (*puVar5 == ':') {
                      if (param_2 != (uchar *)0x0) {
                        if (param_3 < 3) goto LAB_0089b8da;
                        __mbsnbcpy_s(param_2,0xffffffff,param_1,2);
                      }
                      param_1 = puVar5 + 1;
                    }
                    else if (param_2 != (uchar *)0x0) {
                      *param_2 = '\0';
                    }
                    puVar5 = (uchar *)0x0;
                    _Src = (uchar *)0x0;
                    puVar6 = param_1;
                    if (*param_1 == '\0') {
LAB_0089b855:
                      puVar5 = param_1;
                      if (param_4 != (uchar *)0x0) {
                        *param_4 = '\0';
                      }
                    }
                    else {
                      do {
                        iVar3 = __ismbblead((int)(char)*puVar6);
                        if (iVar3 == 0) {
                          uVar1 = *puVar6;
                          if ((uVar1 == '/') || (uVar1 == '\\')) {
                            puVar5 = puVar6 + 1;
                          }
                          else if (uVar1 == '.') {
                            _Src = puVar6;
                          }
                        }
                        else {
                          puVar6 = puVar6 + 1;
                        }
                        puVar6 = puVar6 + 1;
                      } while (*puVar6 != '\0');
                      if (puVar5 == (uchar *)0x0) goto LAB_0089b855;
                      if (param_4 != (uchar *)0x0) {
                        if (param_5 <= (uint)((int)puVar5 - (int)param_1)) goto LAB_0089b8da;
                        __mbsnbcpy_s(param_4,0xffffffff,param_1,(int)puVar5 - (int)param_1);
                      }
                    }
                    param_1 = puVar5;
                    if ((_Src == (uchar *)0x0) || (_Src < param_1)) {
                      if (param_6 != (uchar *)0x0) {
                        if (param_7 <= (uint)((int)puVar6 - (int)param_1)) goto LAB_0089b8da;
                        __mbsnbcpy_s(param_6,0xffffffff,param_1,(int)puVar6 - (int)param_1);
                      }
                      if (param_8 != (uchar *)0x0) {
                        *param_8 = '\0';
                      }
                      return 0;
                    }
                    if (param_6 != (uchar *)0x0) {
                      if (param_7 <= (uint)((int)_Src - (int)param_1)) goto LAB_0089b8da;
                      __mbsnbcpy_s(param_6,0xffffffff,param_1,(int)_Src - (int)param_1);
                    }
                    if (param_8 == (uchar *)0x0) {
                      return 0;
                    }
                    if ((uint)((int)puVar6 - (int)_Src) < param_9) {
                      __mbsnbcpy_s(param_8,0xffffffff,_Src,(int)puVar6 - (int)_Src);
                      return 0;
                    }
                    goto LAB_0089b8da;
                  }
                }
                else if (param_9 != 0) goto LAB_0089b79a;
              }
            }
            else if (param_7 != 0) goto LAB_0089b790;
          }
        }
        else if (param_5 != 0) goto LAB_0089b77f;
      }
    }
    else if (param_3 != 0) goto LAB_0089b76e;
  }
  bVar2 = true;
LAB_0089b8da:
  if ((param_2 != (uchar *)0x0) && (param_3 != 0)) {
    *param_2 = '\0';
  }
  if ((param_4 != (uchar *)0x0) && (param_5 != 0)) {
    *param_4 = '\0';
  }
  if ((param_6 != (uchar *)0x0) && (param_7 != 0)) {
    *param_6 = '\0';
  }
  if ((param_8 != (uchar *)0x0) && (param_9 != 0)) {
    *param_8 = '\0';
  }
  piVar4 = __errno();
  if ((param_1 == (uchar *)0x0) || (bVar2)) {
    uVar7 = 0x16;
    *piVar4 = 0x16;
    FUN_00893343();
  }
  else {
    uVar7 = 0x22;
    *piVar4 = 0x22;
  }
  return uVar7;
}


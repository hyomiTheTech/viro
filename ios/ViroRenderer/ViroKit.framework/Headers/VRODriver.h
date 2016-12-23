//
//  VRODriver.h
//  ViroRenderer
//
//  Created by Raj Advani on 4/21/16.
//  Copyright © 2016 Viro Media. All rights reserved.
//

#ifndef VRODriver_h
#define VRODriver_h

#include <vector>
#include "VRODefines.h"

class VROGeometry;
class VROMaterial;
class VROGeometrySubstrate;
class VROMaterialSubstrate;
class VROTextureSubstrate;
class VROData;
class VROImage;
class VROVideoTextureCache;
class VROSoundEffect;
class VROAudioPlayer;
class VROTypeface;

enum class VROTextureType;
enum class VROTextureFormat;

/*
 The driver is used to interface with the rendering subsystem (OpenGL,
 Metal, etc.).
 */
class VRODriver {
    
public:
    
    virtual ~VRODriver() {}
    
    virtual VROGeometrySubstrate *newGeometrySubstrate(const VROGeometry &geometry) = 0;
    virtual VROMaterialSubstrate *newMaterialSubstrate(VROMaterial &material) = 0;
    virtual VROTextureSubstrate *newTextureSubstrate(VROTextureType type, std::vector<std::shared_ptr<VROImage>> &images) = 0;
    virtual VROTextureSubstrate *newTextureSubstrate(VROTextureType type, VROTextureFormat format, std::shared_ptr<VROData> data,
                                                     int width, int height) = 0;
    virtual VROVideoTextureCache *newVideoTextureCache() = 0;
    virtual std::shared_ptr<VROSoundEffect> newSoundEffect(std::string fileName) = 0;
    virtual std::shared_ptr<VROAudioPlayer> newAudioPlayer(std::string fileName) = 0;
    virtual std::shared_ptr<VROTypeface> newTypeface(std::string typeface, int size) = 0;

};

#endif /* VRODriver_hpp */